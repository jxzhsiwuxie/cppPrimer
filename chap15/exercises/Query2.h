#ifndef JXZ_QUERY2_H_
#define JXZ_QUERY2_H_

#include <algorithm>
#include <iterator>

#include "QueryResult.h"
#include "TextQuery.h"

class Query;
class Query_base {
    friend class Query;

   private:
    //eval 返回与当前 Query 匹配的 QueryResult
    virtual QueryResult eval(const TextQuery &) const = 0;
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
    // Query(std::shared_ptr<Query_base> query) : q(query) {}
    // std::shared_ptr<Query_base> q;
    Query_base *q;
    Query(Query_base *query) : q(query) {}

   public:
    Query(const std::string &);  //构建一个新的 WordQuery
    //接口函数，调用对应的 Query_base 操作
    QueryResult eval(const TextQuery &t) const { return q->eval(t); }
    std::string repo() const { return q->repo(); }

    //暂时还未实现
    Query(const Query &);
    Query(Query &&);
    Query operator=(const Query &);
    Query operator=(Query &&);
    ~Query();
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
    return new NotQuery(operand);
}

QueryResult NotQuery::eval(const TextQuery &text) const {
    //通过 Query 运算对 eval 进行虚调用
    auto result = query.eval(text);
    //开始时结果 set 为空
    auto ret_lines = std::make_shared<std::set<line_no>>();
    //在运算对象出现的所有行中进行迭代
    auto beg = result.begin(), end = result.end();
    //对于输入文件的每一行，如果该行不在 result 中，则将其添加到 ret_lines
    auto sz = result.get_file()->size();
    for (std::size_t n = 0; n != sz; ++n) {
        if (beg == end || *beg != n)
            ret_lines->insert(n);
        else if (beg != end)
            ++beg;
    }

    return QueryResult(repo(), ret_lines, result.get_file());
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
    return new AndQuery(lhs, rhs);
}

QueryResult AndQuery::eval(const TextQuery &text) const {
    //通过 Query 成员 lhs 和 rhs 进行的虚调用
    //调用 eval 返回每个运算对象的 QueryResult
    auto right = rhs.eval(text), left = lhs.eval(text);
    //保存 left 和 right 的交集 set
    auto ret_lines = std::make_shared<std::set<line_no>>();
    std::set_intersection(left.begin(), left.end(), right.begin(), right.end(), std::inserter(*ret_lines, ret_lines->begin()));
    return QueryResult(repo(), ret_lines, left.get_file());
}

class OrQuery : public BinaryQuery {
    friend Query operator|(const Query &, const Query &);

   private:
    OrQuery(const Query &left, const Query &right) : BinaryQuery(left, right, "|") {}
    //定义继承而来的虚函数
    QueryResult eval(const TextQuery &) const;
};

inline Query operator|(const Query &lhs, const Query &rhs) {
    return new OrQuery(lhs, rhs);
}

QueryResult OrQuery::eval(const TextQuery &text) const {
    //通过 Query 成员 lhs 和 rhs 进行的虚调用
    //调用 eval 返回每个运算对象的 QueryResult
    auto right = rhs.eval(text), left = lhs.eval(text);
    //将左侧运算对象所得的行号拷贝到结果 set 中
    auto ret_lines = std::make_shared<std::set<line_no>>(left.begin(), left.end());
    //插入右侧运算对象所得的行号
    ret_lines->insert(right.begin(), right.end());
    //返回一个新的 QueryResult，包含 lhs 和 rhs 的并集
    return QueryResult(repo(), ret_lines, left.get_file());
}

#endif