//练习 14.39：修改上一题的程序令其报告长度在 1 至 9 之间的单词有多少个、长度在 10 以上的单词又有多少个。

#include <cstddef>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::getline;
using std::ifstream;
using std::istringstream;
using std::map;
using std::size_t;
using std::string;
using std::vector;

class FindLengthStr {
   private:
    size_t sz;

   public:
    FindLengthStr(size_t n) : sz(n) {}
    ~FindLengthStr() = default;

    bool operator()(const string &s) const {
        if (sz < 10)
            return sz == s.size();
        else
            return s.size() >= 10;
    }
};

int main() {
    ifstream ifs("ex_14.37.cpp");
    string line, word;
    map<size_t, vector<string>> result;

    //丢弃前两行
    getline(ifs, line);
    getline(ifs, line);

    while (getline(ifs, line)) {
        istringstream iss(line);
        while (iss >> word) {
            for (size_t i = 1; i < 11; ++i) {
                if (FindLengthStr(i)(word))
                    result[i].push_back(word);
            }
        }
    }

    for (auto it = result.begin(); it != result.end(); ++it) {
        cout << "长度为 " << it->first << " 的单词有 " << it->second.size() << " 个，分别是：" << endl;
        cout << '\t';
        for (const auto &s : it->second)
            cout << s << "  ";
        cout << endl;
    }

    return 0;
}
