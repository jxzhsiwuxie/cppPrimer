//练习 2.42：根据尼自己的理解重写一个 Sales_data.h 头文件，
//并以此为基础重做 2.6.22 节（第 67 页）的练习。

#include <iostream>
#include <string>
#include "Sales_data.h"

int main()
{
    //读取多条销售记录，统计每个 ISBN 有几条记录以及同一个 ISBN 和。
    Sales_data currentData, currentTotalData;
    double price;
    int count = 0;
    if (std::cin >> currentTotalData.bookNo)
    {
        //读取第一条记录，确保确实有数据
        count = 1;
        std::cin >> currentTotalData.units_solid >> price;
        currentTotalData.revenue += currentTotalData.units_solid * price;

        while (std::cin >> currentData.bookNo >> currentData.units_solid >> price)
        {
            if (currentData.bookNo == currentTotalData.bookNo)
            {
                ++count;
                currentData.revenue = currentData.units_solid * price;
                currentTotalData.units_solid += currentData.units_solid;
                currentTotalData.revenue += currentData.revenue;
            }
            else
            {
                //输出上一条记录总和
                std::cout << "ISBN 为 " << currentTotalData.bookNo << " 的记录共有 " << count << " 条，";
                std::cout << "总销售数量为 " << currentTotalData.units_solid << "，总销售额为 ￥" << currentTotalData.revenue << std::endl;
                //设置当前记录总和
                count = 1;
                currentTotalData.bookNo = currentData.bookNo;
                currentTotalData.units_solid = currentData.units_solid;
                currentData.revenue = currentData.units_solid * price;
                currentTotalData.revenue = currentData.revenue;
            }
        }
        //循环结束，打印最后一组 ISBN 的总和
        std::cout << "ISBN 为 " << currentTotalData.bookNo << " 的记录共有 " << count << " 条，";
        std::cout << "总销售数量为 " << currentTotalData.units_solid << "，总销售额为 ￥" << currentTotalData.revenue << std::endl;
    }
    else
    {
        return -1;
    }

    return 0;
}