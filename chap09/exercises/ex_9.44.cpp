//练习 9.44：重写上一题的函数，这次使用下标和 replace。

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

    decltype(s.size()) pos = 0;
    while (pos < s.size()) {
        string tmp = s.substr(pos, oldVal.size());
        if (tmp == oldVal) {
            s.replace(pos, oldVal.size(), newVal);
            pos += newVal.size();
        } else {
            ++pos;
        }
    }
    return s;
}