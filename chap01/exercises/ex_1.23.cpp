//练习 1.23：编写程序，读取多条销售记录，并统计每个 ISBN（每本书）有几条销售记录。

#include <iostream>
#include "Sales_item.h"

int main()
{
    std::cout << "输入多条书籍销售记录：" << std::endl;
    Sales_item currentItem, valItem;
    int count = 0;

    if (std::cin >> currentItem)
    {
        ++count;
        while (std::cin >> valItem)
        {
            if (currentItem.isbn() == valItem.isbn())
            {
                ++count;
            }
            else
            {
                std::cout << "书籍 " << currentItem.isbn() << " 的记录有 " << count << " 条。" << std::endl;

                currentItem = valItem;
                count = 1;
            }
        }
        std::cout << "书籍 " << currentItem.isbn() << " 的记录有 " << count << " 条。" << std::endl;
    }

    return 0;
}