//练习 2.17：执行下面的代码将输出什么结果？

#include <iostream>

int main()
{
    int i, &ri = i;
    i = 5;
    ri = 10;

    std::cout << i << " " << ri << std::endl;   //10 10

    return 0;
}