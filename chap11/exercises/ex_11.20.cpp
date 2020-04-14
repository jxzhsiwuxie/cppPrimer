//练习 11.20：重写 11.1 节练习（第 376 页）的单词奇数程序，使用 insert 代替下标操作。你认为哪个程序更容易编写和阅读？解释原因。

#include <cctype>
#include <cstddef>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>

using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::pair;
using std::set;
using std::size_t;
using std::string;

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
    map<string, size_t> word_cout;
    string word;

    set<string> exclude = {"The", "But", "And", "Or", "An", "A", "the", "but", "and", "or", "an", "a"};

    cout << "输入一句话（英文）：" << endl;
    while (cin >> word) {
        processStr(word);

        //只统计不在 exclude 中的单词
        if (exclude.find(word) == exclude.end()) {
            //如果 word 已经在 word_count 中，则 insert 什么也不做。
            // auto ret = word_cout.insert({word, 1});
            pair<map<string, size_t>::iterator, bool> ret = word_cout.insert({word, 1});
            if(!ret.second)
                ++ret.first->second;
        }
    }

    for (const auto &w : word_cout)
        cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times" : " time") << endl;

    return 0;
}


/*
* 当前写法更容易编写和阅读。
*/
