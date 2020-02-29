//定义改进的 Sales_data 类，
//包含 2 个用于接口的成员函数 combine 和 isbn，
//包含一个内部实现用成员函数 avg_price。
//额外实现 3 个用于接口的非成员函数 add、read 和 print。

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

struct Sales_data {
    std::string bookNo;            //书籍 ISBN 号
    unsigned int units_solid = 0;  //销售数量
    double revenue = 0.0;          //销售收入

    std::string isbn() const { return bookNo; }
    Sales_data &combine(const Sales_data &);
    double avg_price() const;
};

//Sales_data 的非成员接口函数
Sales_data add(const Sales_data &, Sales_data &);
std::ostream &print(std::ostream &, const Sales_data &);
std::istream &read(std::istream &, Sales_data &);

//成员函数定义
double Sales_data::avg_price() const {
    if (units_solid == 0)
        return 0;
    else
        return revenue / units_solid;
}

Sales_data &Sales_data::combine(const Sales_data &rhs) {
    units_solid += rhs.units_solid;
    revenue += rhs.revenue;
    return *this;
}

//非成员函数定义
Sales_data add(const Sales_data &lhs, Sales_data &rhs) {
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

std::ostream &print(std::ostream &os, const Sales_data &item) {
    os << item.isbn() << " " << item.units_solid << " "
       << item.revenue << " " << item.avg_price();

    return os;
}

std::istream &read(std::istream &is, Sales_data &item) {
    double price = 0;
    is >> item.bookNo >> item.units_solid >> price;
    item.revenue = item.units_solid * price;

    return is;
}
