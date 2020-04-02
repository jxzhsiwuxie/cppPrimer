//练习 10.13：标准库定义了名为 partition 的算法，它接受一个谓词，对容器内容进行划分，使得谓词为 true 的值排在容器的前半部分，
//而使得谓词为 false 的值排在后半部分。算法返回一个迭代器，指向最后一个使得谓词为 true 的元素之后的位置。编写函数，
//接受一个 string，返回一个 bool 值，指出 string 是否有 5 个或更多字符。使用此函数划分 words。打印出长度大于等于 5 的元素。

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::partition;
using std::string;
using std::vector;

bool lengthLessThan5(const string &);

int main() {
    vector<string> words = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};

    cout << "初始时 words 中包含的 string 为：" << endl;
    for (const auto &s : words)
        cout << s << " ";
    cout << endl;
    cout << "-----------------------------------" << endl;

    auto it = partition(words.begin(), words.end(), lengthLessThan5);

    cout << "经过 partition 算法处理后 words 中包含的 string 为：" << endl;
    for (const auto &s : words)
        cout << s << " ";
    cout << endl;
    cout << "-----------------------------------" << endl;

    cout << "words 中长度大于等于 5 的 string 为：" << endl;
    while (it != words.end())
        cout << (*it++) << " ";
    cout << endl;

    return 0;
}

bool lengthLessThan5(const string &s) {
    return s.size() < 5;
}
