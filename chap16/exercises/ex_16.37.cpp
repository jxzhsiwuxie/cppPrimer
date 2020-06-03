//练习 16.37：标准库 max 函数有两个参数，它返回实参中的较大者。此函数有一个模板类型参数。你能在调用 max 时传递给它一个 int 和 double 么？
//如果可以，如何做？如果不可以，为什么？

/*
* 可以。显式指定模板实参。
*/

#include <algorithm>
#include <iostream>

int main() {
    double res = std::max<double>(10, 9.99);

    std::cout << res << std::endl;

    return 0;
}
