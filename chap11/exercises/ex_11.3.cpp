//练习 11.3：编写你自己的单词统计程序。

#include <cstddef>
#include <iostream>
#include <map>
#include <set>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::set;
using std::size_t;
using std::string;

int main() {
    //统计每个单词在输入中出现的次数
    map<string, size_t> word_cout;
    string word;

    set<string> exclude = {"The", "But", "And", "Or", "An", "A", "the", "but", "and", "or", "an", "a"};

    while (cin >> word)
        //只统计不在 exclude 中的单词
        if (exclude.find(word) == exclude.end())
            ++word_cout[word];

    for (const auto &w : word_cout)
        cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times" : " time") << endl;

    return 0;
}
