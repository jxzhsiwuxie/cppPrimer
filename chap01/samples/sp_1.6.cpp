//从一个文件中读取销售记录，生成每本书的销售报告，显示售出册数、总销售额和平均销售价。
//假定每个 ISBN 书号的所有销售记录在文件中是聚在一起保存的。
//将每个 ISBN 的所有数据合并起来保存到名为 total 的变量中。
//使用名为 trans 的变量保存读取的每条销售记录。
//如果 trans 和 total 指向相同的 ISBN 则更新 total 的值，否则打印 total 的值并将其更新为刚刚读取的数据（trans）。

#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item total;
    if (std::cin >> total)
    {
        Sales_item trans;
        while (std::cin >> trans)
        {
            if (total.isbn() == trans.isbn())
            {
                total += trans;
            }
            else
            {
                std::cout << total << std::endl;
                total = trans;
            }
        }
        //打印最后一本书的结果
        std::cout << total << std::endl;
    }
    else
    {
        std::cerr << "No data?!" << std::endl;
        return -1;
    }

    return 0;
}