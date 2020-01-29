//练习 1.10：除了 ++ 运算符将运算对象的值增加 1 之外，还有一个递减运算符 （--）实现将值减少 1。
//编写程序，使用递减运算符在循环中按递减顺序打印出 10 到 0 之间的整数。

#include <iostream>

int main()
{
    int val = 11;
    while (val-- > 0)
        std::cout << val << std::endl;
    return 0;
}