//练习 10.11：编写程序，使用 stable_sort 和 isShorter 将传递给你的 elimDups 版本的 vector 排序。打印 vector 中的内容，验证你的程序的正确性。

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::sort;
using std::string;
using std::unique;
using std::vector;

bool isShorter(const string &, const string &);

void elimDups(vector<string> &);

int main() {
    vector<string> words = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};

    elimDups(words);

    return 0;
}

bool isShorter(const string &s1, const string &s2) {
    return s1.size() < s2.size();
}

void elimDups(vector<string> &words) {
    cout << "原始的 vector 中的字符串序列为：" << endl;
    for (const auto &s : words)
        cout << s << " ";
    cout << endl;
    cout << "-----------------------------------" << endl;

    sort(words.begin(), words.end());
    cout << "经过 sort 算法处理后 vector 中的字符串序列为：" << endl;
    for (const auto &s : words)
        cout << s << " ";
    cout << endl;
    cout << "-----------------------------------" << endl;

    auto end_unique = unique(words.begin(), words.end());
    cout << "经过 unique 算法处理后 vector 中的字符串序列为：" << endl;
    for (const auto &s : words)
        cout << s << " ";
    cout << endl;
    cout << "-----------------------------------" << endl;

    words.erase(end_unique, words.end());
    cout << "经过 erase 处理后 vector 中的字符串序列为：" << endl;
    for (const auto &s : words)
        cout << s << " ";
    cout << endl;
    cout << "-----------------------------------" << endl;

    std::stable_sort(words.begin(), words.end(), isShorter);
    cout << "经过稳定排序 stable_sort 处理后 vector 中的字符串序列为：" << endl;
    for (const auto &s : words)
        cout << s << " ";
    cout << endl;
    cout << "-----------------------------------" << endl;
}