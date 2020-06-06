//练习 16.56：编写并测试可变参数版本的 errorMsg。

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::ostream;
using std::string;

template <typename T, typename... Args>
ostream &errorMsg(ostream &os, const T &t) {
    os << t << endl;
    return os;
}

template <typename T, typename... Args>
ostream &errorMsg(ostream &os, const T &t, const Args &... rest) {
    os << t << ", ";
    return errorMsg(os, rest...);
}

int main() {
    int i = 0;
    double d = 1.23;
    string s = "abc";

    errorMsg(cout, i, d, s);

    return 0;
}