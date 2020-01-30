//练习 2.34：基于上一个练习中的变量和语句编写一段程序，输出赋值前后变量的内容，
//你刚才的推断正确么？如果不对，请反复研读本节的示例直到尼明白错在何处为止。

#include <iostream>

int main()
{
    //本节定义的变量
    int i = 0, &r = i;
    auto a = r;
    const int ci = i, &cr = ci;
    auto b = ci;
    auto c = cr;
    auto d = &i;
    auto e = &ci;
    const auto f = ci;
    auto &g = ci;

    //练习 2.33 的语句
    a = 42;
    b = 42;
    c = 42;
    // d = 42; //编译器报错
    // e = 42; //编译器报错
    // g = 42; //编译器报错

    std::cout << "a 的值：" << a << "; ";
    std::cout << "b 的值：" << b << "; ";
    std::cout << "c 的值：" << c << "; ";
    std::cout << "d 的值：" << d << "; ";
    std::cout << "e 的值：" << e << "; ";
    std::cout << "g 的值：" << g << "; ";
    std::cout << std::endl;

    return 0;
}
