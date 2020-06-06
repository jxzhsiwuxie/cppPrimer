//练习 16.51：调用本节的每个 foo，确定 sizeof...(Args) 和 sizeof...(rest) 分别返回什么。

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

template <typename T, typename... Args>
void foo(const T &t, const Args... rest) {
    cout << "sizeof...(Args) = " << sizeof...(Args) << endl;
    cout << "sizeof...(rest) = " << sizeof...(rest) << endl;
    cout << "------------------" << endl;
}

int main() {
    int i = 0;
    double d = 3.14;
    string s = "how now brown cow";

    foo(i, s, 42, d);
    foo(s, 42, "hi");
    foo(d, s);
    foo("hi");

    return 0;
}
