//练习 16.50：定义上一个练习中的函数，令它们打印一条身份信息。运行该练习中的代码。
//如果函数调用的行为与你预期的不符，确定你理解了原因。

#include <iostream>
using std::cout;
using std::endl;

template <typename T>
void f(T) {
    cout << "f(T)" << endl;
}

template <typename T>
void f(const T*) {
    cout << "f(const T*)" << endl;
}

template <typename T>
void g(T) {
    cout << "g(T)" << endl;
}

template <typename T>
void g(T*) {
    cout << "g(T*)" << endl;
}

int main() {
    int i = 42, *p = &i;
    const int ci = 0, *p2 = &ci;
    g(42);
    g(p);
    g(ci);
    g(p2);
    f(42);
    f(p);
    f(ci);
    f(p2);
    return 0;
}
