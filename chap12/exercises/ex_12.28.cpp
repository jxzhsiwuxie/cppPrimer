//练习 12.28：编写程序实现文本查询，不要定义类来管理数据。你的程序应该接受一个文件，并于用户交互来查询单词。
//使用 vector、map 和 set 容器来保存文本数据并生成查询结果。

#include <cstddef>
#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::ifstream;
using std::istringstream;
using std::map;
using std::set;
using std::size_t;
using std::string;
using std::vector;

int main() {
    ifstream ifs("strblob.txt");
    vector<string> text;
    string line;
    while (getline(ifs, line))
        text.push_back(line);

    map<string, set<size_t>> word_line;
    string word;
    for (size_t i = 0; i < text.size(); ++i) {
        line = text.at(i);
        istringstream iss(line);
        while (iss >> word) {
            if (word_line.find(word) == word_line.end())
                word_line.insert({word, {i}});
            else
                word_line.find(word)->second.insert(i);
        }
    }

    while (true) {
        cout << "输入一个想要查询的单词，或者输入 q 退出：";
        if (!(cin >> word) || word == "q")
            break;

        auto it = word_line.find(word);
        if (it == word_line.end())
            cout << "文本中没有单词 " << word << endl;
        else {
            auto line_muns = it->second;
            for (auto cbeg = line_muns.cbegin(); cbeg != line_muns.cend(); ++cbeg)
                cout << "第 " << *cbeg << " 行：" << text.at(*cbeg) << endl;
        }
    }

    return 0;
}
