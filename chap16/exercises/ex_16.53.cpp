//练习 16.53：编写你自己版本的 print 函数，并打印一个、两个及五个实参来测试它，要打印的每个实参都应有不同的类型。

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::ostream;
using std::string;

template <typename T>
ostream &print(ostream &os, const T &t) {
    return os << t << endl;
}

template <typename T, typename... Args>
ostream &print(ostream &os, const T &t, const Args... rest) {
    os << t << ", ";
    return print(os, rest...);
}

int main() {
    int i = 0;
    double d = 1.1;
    char c = 'a';
    const char *str = "aaaa";
    string s = "abcd";

    print(cout, i);
    print(cout, i, d);
    print(cout, i, d, c, str, s);
}