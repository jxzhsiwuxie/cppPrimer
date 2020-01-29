//练习 1.17：如果输入的所有值相等，本节的程序会输出什么？
//如果没有重复值，输出又会是怎样？

#include <iostream>

int main()
{
    std::cout << "Enter some numbers:";
    int currVal = 0, val = 0;
    if (std::cin >> currVal)
    {
        int cnt = 1;
        while (std::cin >> val)
        {
            if (currVal == val)
                ++cnt;
            else
            {
                std::cout << currVal << " occurs " << cnt << " times." << std::endl;
                currVal = val;
                cnt = 1;
            }
        }
    }

    return 0;
}

//如果输入的所有值都相等，则 while 内的 else 部分不会执行，因此不会输出任何东西。
//如果没有重复值，最后一个值不会被统计。