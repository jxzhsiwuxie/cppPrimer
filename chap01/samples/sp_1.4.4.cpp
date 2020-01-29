//统计在输入中，每个值连续出现多少次。

#include <iostream>

int main()
{
    std::cout << "Enter some numbers:";
    //currVal 是我们正在统计的数字，我们将读入的新值存入 val
    int currVal = 0, val = 0;
    //读取第一个数，并确保确实有数据可以处理
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