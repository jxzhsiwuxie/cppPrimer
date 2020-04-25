#ifndef TEXT_QUERY_H_
#define TEXT_QUERY_H_

#include <cstddef>
#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <sstream>
#include <string>

class TextQuery {
   private:
    std::shared_ptr<std::map<std::string, std::set<std::size_t>>> result;
    std::map<std::size_t, std::string> text_lines;

   public:
    TextQuery(std::ifstream &);
    std::shared_ptr<std::map<std::string, std::set<std::size_t>>> getText() { return result; }
    ~TextQuery();
};

TextQuery::TextQuery(std::ifstream &ifs) : result(std::make_shared<std::map<std::string, std::set<std::size_t>>>()), text_lines() {
    std::string line;
    std::size_t line_num = 0;

    while (std::getline(ifs, line))
        text_lines.insert({line_num++, line});

    auto cbeg = text_lines.cbegin(), cend = text_lines.cend();
    while (cbeg != cend) {
        line = cbeg->second;
        line_num = cbeg->first;

        std::istringstream iss(line);
        std::string word;
        while (iss >> word) {
            if (result->find(word) == result->end())
                result->insert({word, {line_num}});
            else
                result->find(word)->second.insert(line_num);
        }

        ++cbeg;
    }
}

TextQuery::~TextQuery() {
}

#endif