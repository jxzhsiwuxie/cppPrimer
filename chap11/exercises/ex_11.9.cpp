//练习 11.9：定义一个 map，将单词与一个 list 的行号关联，list 中保存的是单词所出现的行号。

#include <cstddef>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <sstream>
#include <string>

using std::cout;
using std::endl;
using std::getline;
using std::ifstream;
using std::istringstream;
using std::list;
using std::map;
using std::size_t;
using std::string;

void process_str(string &str) {
    char c = str.back();
    if (std::ispunct(c))
        str.pop_back();

    for (auto &c : str)
        c = std::tolower(c);

    return;
}

int main() {
    ifstream ifs("ex_11.9.txt");
    map<string, list<size_t>> record_map;

    string line, str;
    size_t line_number = 0;
    while (getline(ifs, line)) {
        ++line_number;

        istringstream iss(line);

        while (iss >> str) {
            process_str(str);

            if (str.empty())
                continue;

            if (record_map.find(str) != record_map.end())
                record_map[str].push_back(line_number);
            else
                record_map[str] = {line_number};
        }
    }

    cout << "文件读取完毕！" << endl;
    for (const auto &item : record_map) {
        cout << "单词 " << item.first << " 所在的行号为：" << endl;
        for (const auto n : item.second)
            cout << n << " ";
        cout << endl;
    }

    return 0;
}
