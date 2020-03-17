//练习 9.43：编写函数，接受三个 string 参数 s、oldVal 和 newVal。使用迭代器以及 insert 和 erase  函数将 s 中所有
//oldVal 替换为 newVal。测试你的程序，用它替换通用的简写形式，如，将 “tho” 替换为 “though”，将 “thru” 替换为 “through”。

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

string &myReplace(string &, const string &, const string &);

int main() {
    string str("abc tho deftho hijk thru cccthru");
    cout << "初始时 str 为：" << str << endl;

    myReplace(str, "tho", "though");
    cout << "将 tho替换为 though后 str 为：" << str << endl;

    myReplace(str, "thru", "through");
    cout << "将 tho替换为 though后 str 为：" << str << endl;

    return 0;
}

string &myReplace(string &s, const string &oldVal, const string &newVal) {
    auto prev = s.begin(), tail = prev + oldVal.size();

    //保证 s 的最后几位是 oldVal 的情况下也能匹配到
    while (tail != s.end() + 1 && prev != s.end()) {
        string tmp(prev, tail);
        if (tmp == oldVal) {
            auto pos = prev - s.begin();
            s.erase(prev, tail);
            s.insert(prev, newVal.begin(), newVal.end());
            //插入操作之后如果 stirng 重新分配内存，则会导致之前所有的迭代器失效
            prev = s.begin() + pos + newVal.size();
            tail = prev + oldVal.size();
        } else {
            ++prev;
            ++tail;
        }
    }
    return s;
}