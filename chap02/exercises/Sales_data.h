#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>

struct Sales_data
{
    std::string bookNo;           //书籍 ISBN 号
    unsigned int units_solid = 0; //销售数量
    double revenue = 0.0;         //销售收入
};

#endif