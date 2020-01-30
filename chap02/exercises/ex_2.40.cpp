//练习 2.40：根据自己的理解写出 Sales_data 类，最好与书中的例子有所区别。

#include <string>

struct Sales_data
{
    std::string bookNo;           //书籍 ISBN 号
    unsigned int units_solid = 0; //销售数量
    double revenue = 0.0;         //销售收入
};