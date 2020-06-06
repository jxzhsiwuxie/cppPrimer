//练习 16.54：如果我们对一个没有 << 运算符的类型调用 print，会发生什么？

/*
* 编译无法通过。
*/

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

struct X {
};

int main() {
    X x1, x2;
    int i;

    print(cout, i);
    print(cout, x1, i);
}