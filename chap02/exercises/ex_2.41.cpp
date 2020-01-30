//练习 2.41：使用尼自己的 Sales_data 类重写 1.5.1 节（第 20 页）、1.5.2 节（第 21 页）和 1.6.1 节（第 22 页）的练习。
//眼下先把 Sales_data 类的定义和 main 函数放在同一个文件里。

/*
* 1.5.1 节练习：编写一个程序，读取一组销售记录，将每条记录打印到标准输出上。
*              编写程序，读取多个具有相同 ISBN 的 Sales_data 对象，输出它们的和。
* 1.5.2 节练习：编写程序，读取多条销售记录，并统计每个 ISBN 有几条销售记录。
* 1.6.1 节练习：编译并运行书店程序。
*
* 这里使用 Sales_data.txt 来批量输入数据。
* 在当前目录下利用  g++ -fexec-charset=gbk -o main .\ex_2.41.cpp 编译程序。
* 编译完之后再 cmd 窗口使用 main.exe < sales_data.txt 命令即可。
* 或者在 powershell 窗口使用  Get-Content .\sales_data.txt | .\main.exe 命令也可以。
*
*/

#include <iostream>
#include <string>

struct Sales_data
{
    std::string bookNo;           //书籍 ISBN 号
    unsigned int units_solid = 0; //销售数量
    double revenue = 0.0;         //销售收入
};

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