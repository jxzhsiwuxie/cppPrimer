#ifndef JXZ_TEXT_QUERY_H_
#define JXZ_TEXT_QUERY_H_

#include <cstddef>
#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <sstream>
#include <string>
#include <vector>

#include "DebugDelete.h"
#include "QueryResult.h"

class TextQuery {
   public:
    using line_no = std::vector<std::string>::size_type;

   private:
    std::shared_ptr<std::vector<std::string>> file;  //输入文件
    //每个单词到它所在的行号的映射
    std::map<std::string, std::shared_ptr<std::set<line_no>>> word_map;

   public:
    TextQuery(std::ifstream &);
    ~TextQuery() = default;
    QueryResult query(const std::string &) const;
};

TextQuery::TextQuery(std::ifstream &ifs) : file(new std::vector<std::string>, DebugDelete()) {
    std::string text;
    while (std::getline(ifs, text)) {   //对文中每一行
        file->push_back(text);          //保存此文本
        int n = file->size() - 1;       //当前行号
        std::istringstream line(text);  //将行文本分解为单词
        std::string word;
        while (line >> word) {  //对行中每个单词
            //如果单词不在 word_map 中，以之为下标在 word_map 中添加一项
            auto &lines = word_map[word];                           //lines 是一个 shared_ptr
            if (!lines)                                             //在我们第一次遇到这个单词时，这个指针为空
                lines.reset(new std::set<line_no>, DebugDelete());  //分配一个新的 set
            lines->insert(n);                                       //将此行号插入到 set 中
        }
    }
}

QueryResult TextQuery::query(const std::string &sought) const {
    //如果未找到 sought，我们将返回此 set
    static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);
    //使用 find 而不是下标运算符来查找单词，避免将单词添加到 word_map 中
    auto loc = word_map.find(sought);
    if (loc == word_map.end())
        return QueryResult(sought, nodata, file);
    else
        return QueryResult(sought, loc->second, file);
}

#endif