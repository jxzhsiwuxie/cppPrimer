//练习 1.9：编写程序，使用 while 循环将 50 到 100 的整数相加。

#include <iostream>

int main()
{
    int sum = 0, val = 50;

    while (val <= 100){
        sum += val;
        ++val;
    }

    std::cout << "50 到 100 的和为：" << sum << std::endl;

    return 0;
}