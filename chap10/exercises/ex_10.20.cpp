//练习 10.20：标准库定义了一个名为 count_if 的算法。类似 find_if，函数接受一对迭代器，表示输入范围，还接受一个谓词，会对输入范围中的每个元素执行。
//count_if 返回一个计算值，表示谓词有多少次为真。使用 count_if 重写我们程序中统计有多少单词长度超过 6 的部分。

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

void biggies(vector<string> &, vector<string>::size_type);

string make_plural(std::size_t, const string &, const string &);

int main() {
    vector<string> words = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};

    elimDups(words);

    biggies(words, 6);

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

string make_plural(std::size_t ctr, const string &word, const string &ending) {
    return (ctr > 1) ? word + ending : word;
}

void biggies(vector<string> &words, vector<string>::size_type sz) {
    //将 words 按字典顺序排序，删除重复单词
    elimDups(words);
    //按长度排序，长度相同的单词按照字典排序
    std::stable_sort(words.begin(), words.end(), [](const string &a, const string &b) { return a.size() < b.size(); });
    //计算满足 size() >= sz 的元素的数目
    auto count = std::count_if(words.begin(), words.end(), [=](const string &s) { return s.size() >= sz; });
    cout << "一共有 " << count << " 个长度大于等于" << sz << " 的 " << make_plural(count, "word", "s") << endl;
    //打印长度大于等于给定值的单词
    std::for_each(words.begin(), words.end(), [=](const string &s) {
        if (s.size() >= sz)
            cout << s << " ";
    });
    cout << endl;
}
