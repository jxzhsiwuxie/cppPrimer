//练习 11.38：使用 unordered_map 重写的单词计数程序（参见 11.1 节，第 375 页）和单词转换程序（参见 11.3.6 节，第 391 节）。

#include <cctype>
#include <cstddef>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_map>

using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::set;
using std::size_t;
using std::string;
using std::unordered_map;

//将字符串处理成小写并且不含标点符号的形式（标点符号只存在末尾）
void processStr(string &str) {
    char c = str.back();
    if (std::ispunct(c))
        str.pop_back();

    for (auto &c : str)
        c = std::tolower(c);

    return;
}

int main() {
    //统计每个单词在输入中出现的次数
    unordered_map<string, size_t> word_cout;
    string word;

    set<string> exclude = {"The", "But", "And", "Or", "An", "A", "the", "but", "and", "or", "an", "a"};

    cout << "输入一句话（英文）：" << endl;
    while (cin >> word) {
        processStr(word);

        //只统计不在 exclude 中的单词
        if (exclude.find(word) == exclude.end())
            ++word_cout[word];
    }

    for (const auto &w : word_cout)
        cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times" : " time") << endl;

    return 0;
}
