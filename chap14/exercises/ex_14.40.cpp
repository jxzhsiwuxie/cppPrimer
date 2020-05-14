//练习 14.40：重新编写 10.3.2 节（第 349 页）的 biggies 函数，使用函数对象类代替其中的 lambda 表达式。

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

class Compare {
   private:
    string::size_type sz;

   public:
    Compare() = default;
    Compare(string::size_type n) : sz(n) {}
    ~Compare() = default;

    bool operator()(const string &s1, const string &s2) { return s1.size() < s2.size(); }
    bool operator()(const string &s) { return s.size() >= sz; }
};

bool isShorter(const string &, const string &);

void elimDups(vector<string> &);

void biggies(vector<string> &, vector<string>::size_type);

string make_plural(std::size_t, const string &, const string &);

int main() {
    vector<string> words = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};

    elimDups(words);

    biggies(words, 5);

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
    std::stable_sort(words.begin(), words.end(), Compare());
    //获取一个迭代器，指向第一个满足 size() >= sz 的元素
    auto wc = std::find_if(words.begin(), words.end(), Compare(sz));
    //计算满足 size() >= sz 的元素的数目
    auto count = words.end() - wc;
    cout << "一共有 " << count << " 个长度大于等于" << sz << " 的 " << make_plural(count, "word", "s") << endl;
    //打印长度大于等于给定值的单词
    std::for_each(wc, words.end(), [](const string &s) { cout << s << " "; });
    cout << endl;
}