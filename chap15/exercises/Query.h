#ifndef JXZ_QUERY_H_
#define JXZ_QUERY_H_

#include "QueryResult.h"
#include "TextQuery.h"

class Query;
class Query_base {
    friend class Query;

   private:
    //eval 返回与当前 Query 匹配的 QueryResult
    virtual QueryResult evel(const TextQuery &) const = 0;
    //repo 表示查询的一个 string
    virtual std::string repo() const = 0;

   protected:
    using line_no = TextQuery::line_no;
    virtual ~Query_base() = default;
};

class Query {
    friend Query operator~(const Query &);
    friend Query operator|(const Query &, const Query &);
    friend Query operator&(const Query &, const Query &);

   private:
    Query(std::shared_ptr<Query_base> query) : q(query) {}
    std::shared_ptr<Query_base> q;

   public:
    Query(const std::string &);  //构建一个新的 WordQuery
    //接口函数，调用对应的 Query_base 操作
    QueryResult eval(const TextQuery &t) const { return q->evel(t); }
    std::string repo() const { return q->repo(); }
};

//Query 的输出
std::ostream &operator<<(std::ostream &os, const Query &query) {
    //Query::repo 通过它的 Query_base 指针对 repo() 进行了虚调用
    return os << query.repo();
}

class WordQuery : public Query_base {
    friend class Query;  //Query 使用 WordQuery 的构造函数

   private:
    std::string query_word;  //要查询的单词
    WordQuery(const std::string &s) : query_word(s) {}
    //定义继承而来的虚函数
    QueryResult eval(const TextQuery &t) const {
        return t.query(query_word);
    }
    std::string repo() const {
        return query_word;
    }
};

//定义接受一个 string 的 Query 的构造函数
inline Query::Query(const std::string &s) : q(new WordQuery(s)) {}

class NotQuery : public Query_base {
    friend Query operator~(const Query &);

   private:
    Query query;
    NotQuery(const Query &q) : query(q) {}
    //定义继承而来的虚函数
    QueryResult eval(const TextQuery &) const;
    std::string repo() const { return "~(" + query.repo() + ")"; }
};

inline Query operator~(const Query &operand) {
    return std::shared_ptr<Query_base>(new NotQuery(operand));
}

class BinaryQuery : public Query_base {
   protected:
    Query lhs, rhs;     //左侧和右侧运算对象
    std::string opSym;  //运算符的名字
    BinaryQuery(const Query &l, const Query &r, std::string s) : lhs(l), rhs(r), opSym(s) {}
    //抽象类 BinaryQuery 不定义 eval
    std::string repo() const {
        return "(" + lhs.repo() + " " + opSym + " " + rhs.repo() + ")";
    }
};

class AndQuery : public BinaryQuery {
    friend Query operator&(const Query &, const Query &);

   private:
    AndQuery(const Query &left, const Query &right) : BinaryQuery(left, right, "&") {}
    //定义继承而来的虚函数
    QueryResult eval(const TextQuery &) const;
};

inline Query operator&(const Query &lhs, const Query &rhs) {
    return std::shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}

class OrQuery : public BinaryQuery {
    friend Query operator|(const Query &, const Query &);

   private:
    OrQuery(const Query &left, const Query &right) : BinaryQuery(left, right, "|") {}
    //定义继承而来的虚函数
    QueryResult eval(const TextQuery &) const;
};

inline Query operator|(const Query &lhs, const Query &rhs) {
    return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}

#endif