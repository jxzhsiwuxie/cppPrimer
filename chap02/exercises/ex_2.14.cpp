//练习 2.14：下面的程序合法么？如果合法，输出什么？

#include <iostream>

int main()
{
    int i = 100, sum = 0;
    for (int i = 0; i != 10; ++i)
        sum += i;

    std::cout << i << " " << sum << std::endl;
    return 0;
}

//程序合法，输出： 100 45 