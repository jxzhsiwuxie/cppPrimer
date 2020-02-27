//练习 6.51：编写函数 f 的 4 个版本，令其各输出一条可以区分的信息。验证上一个练习的答案，
//如果你回答错了，反复研究本节内容直到你弄清楚自己错在何处。

#include <iostream>

void f();
void f(int);
void f(int, int);
void f(double, double = 3.14);

int main() {
    // f(2.56, 42);     //调用具有二义性，编译无法通过
    f(42);
    f(42, 0);
    f(2.56, 3.14);

    return 0;
}

void f() {
    std::cout << "调用了 void f() 版本的函数" << std::endl;
}

void f(int a) {
    std::cout << "调用了 void f(int) 版本的函数" << std::endl;
}

void f(int a, int b) {
    std::cout << "调用了 void f(int, int) 版本的函数" << std::endl;
}

void f(double a, double b) {
    std::cout << "调用了 void f(double, double = 3.14) 版本的函数" << std::endl;
}


/*
* 可验证上一个练习结果是正确的。
*/
