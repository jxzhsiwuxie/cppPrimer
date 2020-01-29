//读取数量不定的输入数据

#include <iostream>
int main()
{
    int sum = 0, val = 0;
    std::cout << "输入几个数字，然后以非数字的字母结束" << std::endl;
    while (std::cin >> val)
        sum += val;

    std::cout << "Sum is " << sum << std::endl;

    return 0;
}