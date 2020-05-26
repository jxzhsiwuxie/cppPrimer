#ifndef JXZ_SALES_DATA_H_
#define JXZ_SALES_DATA_H_

#include <cstddef>
#include <iostream>
#include <string>
#include <utility>

class Sales_data {
    //类的接口，友元
    friend Sales_data add(const Sales_data &, Sales_data &);
    friend std::ostream &print(std::ostream &, const Sales_data &);
    friend std::istream &read(std::istream &, Sales_data &);

    //重载的加法、输入、输出运算符
    friend Sales_data operator+(const Sales_data &, const Sales_data &);
    friend std::ostream &operator<<(std::ostream &, const Sales_data &);
    friend std::istream &operator>>(std::istream &, Sales_data &);
    friend Sales_data operator*(Sales_data &, std::size_t);
    friend Sales_data operator*(std::size_t, Sales_data &);

   private:
    std::string bookNo;            //书籍 ISBN 号
    unsigned int units_solid = 0;  //销售数量
    double revenue = 0.0;          //销售收入
    inline double avg_price() const { return units_solid ? revenue / units_solid : 0; }

   public:
    //构造函数，使用委托构造函数
    Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), units_solid(n), revenue(n * p) {}
    Sales_data(const std::string &s) : Sales_data(s, 0, 0) {}
    Sales_data() : Sales_data("", 0, 0) {}
    Sales_data(std::istream &);

    //接口，成员函数
    std::string isbn() const { return bookNo; }
    Sales_data &combine(const Sales_data &);

    //重载赋值、复合赋值运算符
    Sales_data &operator=(const Sales_data &);
    Sales_data &operator+=(const Sales_data &);
    Sales_data &operator=(const std::string &);

    explicit operator std::string() const { return bookNo; }
    explicit operator double() const { return revenue; }
};

//Sales_data 的非成员接口函数声明
Sales_data add(const Sales_data &, Sales_data &);
std::ostream &print(std::ostream &, const Sales_data &);
std::istream &read(std::istream &, Sales_data &);

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

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data sum;
    sum.bookNo = lhs.bookNo;
    sum.units_solid = lhs.units_solid + rhs.units_solid;
    sum.revenue = lhs.revenue + rhs.revenue;
    return sum;
}

std::ostream &operator<<(std::ostream &os, const Sales_data &item) {
    os << item.bookNo << " " << item.units_solid << " " << item.revenue;
    return os;
}

std::istream &operator>>(std::istream &is, Sales_data &item) {
    double price;
    is >> item.bookNo >> item.units_solid >> price;
    if (is)
        item.revenue = item.units_solid * price;
    else
        item = Sales_data();
    return is;
}

Sales_data &Sales_data::operator=(const Sales_data &rhs) {
    bookNo = rhs.bookNo;
    units_solid = rhs.units_solid;
    revenue = rhs.revenue;

    return *this;
}

Sales_data &Sales_data::operator=(const std::string &isbn) {
    bookNo = isbn;
    units_solid = 0;
    revenue = 0;
}

Sales_data &Sales_data::operator+=(const Sales_data &rhs) {
    units_solid += rhs.units_solid;
    revenue += rhs.revenue;

    return *this;
}

Sales_data operator*(Sales_data &item, std::size_t n) {
    Sales_data res = item;
    res.units_solid *= n;
    res.revenue *= n;
    return res;
}

Sales_data operator*(std::size_t n, Sales_data &item) {
    return item * n;
}

#endif
