//练习 13.13：理解拷贝控制成员和构造函数的一个好方法是定义一个简单的类，为该类定义这些成员，每个成员都打印出自己的名字：
// struct X {
//     X() {std::cout << "X()" << std::endl;}
//     X(const X &) {std::cout << "X(const X &)" << std::endl;}
// }
//给 X 添加拷贝赋值运算符和析构函数，并编写一个程序以不同的方式使用 X 的对象：将它们作为非引用和引用参数传递；
//动态分配它们；将它们存放于容器中；诸如此类。观察程序的输出，知道你确认理解了什么时候会使用拷贝控制成员，以及为什么会使用它们。
//当你观察程序输出时，记住编译器可以掠过对拷贝构造函数的调用。

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

struct X {
    X() { cout << "X 的默认构造函数被调用了" << endl; }
    X(const X &) { cout << "X 的拷贝构造函数被调用了" << endl; }
    ~X() { cout << "X 的析构函数被调用了" << endl; }
    X &operator=(const X &) {
        cout << "X 的赋值构造函数被调用了" << endl;
        return *this;
    }
};

void test(const X varx, const X &refx) {
    X x0, x1, x2(varx), x3(refx);

    X *xptr0 = new X();
    X *xptr1 = new X(varx);

    x0 = x2;
    x1 = *xptr0;

    delete xptr0;
    delete xptr1;

    return;
}

int main() {
    X x00, x01;

    cout << "---------------------------" << endl;
    test(x00, x01);

    return 0;
}
