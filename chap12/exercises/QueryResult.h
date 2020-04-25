#ifndef QUERY_RESULT_H_
#define QUERY_RESULT_H_

#include <cstddef>
#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <sstream>
#include <string>

class QueryResult {
   private:
    std::shared_ptr<std::map<std::string, std::set<std::size_t>>> result;
    std::map<std::string, std::set<std::size_t>> query_result;

   public:
    QueryResult() : result(), query_result() {}
    ~QueryResult();

    void setText(std::shared_ptr<std::map<std::string, std::set<std::size_t>>> result) {
        this->result = result;
    }

    std::ostream &print(std::ostream &os, const std::string &word) {
        if (result->find(word) == result->end())
            os << "没有找到这个单词" << std::endl;
        else {
            auto it = result->find(word);
            auto line_nums = it->second;
            for (auto i = line_nums.begin(); i != line_nums.end(); ++i)
                os << "单词 " << word << " 在第 " << *i << " 行" << std::endl;
        }

        return os;
    }
};

QueryResult::~QueryResult() {
}

#endif