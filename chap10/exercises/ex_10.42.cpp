//练习 10.42：使用 list 代替 vector 重新实现 10.2.3 节（第 343 页）中的去除重复单词的程序。


#include <algorithm>
#include <iostream>
#include <string>
#include <list>

using std::cout;
using std::endl;
using std::sort;
using std::string;
using std::unique;
using std::list;

void elimDups(list<string> &words) {
    cout << "原始的 list 中的字符串序列为：" << endl;
    for (const auto &s : words)
        cout << s << " ";
    cout << endl;

    words.sort();
    cout << "经过 sort 算法处理后 list 中的字符串序列为：" << endl;
    for (const auto &s : words)
        cout << s << " ";
    cout << endl;

    words.unique();
    cout << "经过 unique 算法处理后 list 中的字符串序列为：" << endl;
    for (const auto &s : words)
        cout << s << " ";
    cout << endl;
}

int main() {
    list<string> words = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};

    elimDups(words);

    return 0;
}
