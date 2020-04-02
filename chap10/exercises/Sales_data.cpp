#include "Sales_data.h"
#include <iostream>

//构造函数定义
Sales_data::Sales_data(std::istream &is) : Sales_data() {
    std::cout << "调用了只有一个 istream 参数的构造函数" << std::endl;
    read(is, *this);
}

//成员函数定义
Sales_data &Sales_data::combine(const Sales_data &rhs) {
    units_solid += rhs.units_solid;
    revenue += rhs.revenue;
    return *this;
}

//Sales_data 的非成员接口函数定义
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