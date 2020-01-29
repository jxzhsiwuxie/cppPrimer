//雷神之锤游戏中，逆平方根算法。

#include <iostream>

float QRSqrt(float number);

int main()
{
    float number;
    std::cout << "输入一个浮点数字：";
    std::cin >> number;

    std::cout << number << " 的平方根的倒数为：" << QRSqrt(number) << std::endl;
    std::cout << number << " 的平方根为：" << 1 / QRSqrt(number) << std::endl;

    return 0;
}

float QRSqrt(float number)
{
    long i;
    float x, y;
    const float threehalfs = 1.5f;

    x = number * 0.5f;
    y = number;
    i = *(long *)&y;
    //魔法
    i = 0x5f3759df - (i >> 1);
    y = *(float *)&i;
    //一次迭代
    y = y * (threehalfs - (x * y * y));
    //二次迭代
    y = y * (threehalfs - (x * y * y));
    //三次迭代
    y = y * (threehalfs - (x * y * y));

    return y;
}