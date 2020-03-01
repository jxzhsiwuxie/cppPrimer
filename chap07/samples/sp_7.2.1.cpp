//将 Sales_data 类的非成员接口函数声明成类的友元函数。

#include <iostream>
#include <string>

class Sales_data {
    //类的接口，友元
    friend Sales_data add(const Sales_data &, Sales_data &);
    friend std::ostream &print(std::ostream &, const Sales_data &);
    friend std::istream &read(std::istream &, Sales_data &);

   private:
    std::string bookNo;            //书籍 ISBN 号
    unsigned int units_solid = 0;  //销售数量
    double revenue = 0.0;          //销售收入
    double avg_price() const { return units_solid ? revenue / units_solid : 0; }

   public:
    //构造函数
    Sales_data() = default;
    Sales_data(const std::string &s) : bookNo(s){};
    Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), units_solid(n), revenue(n * p) {}
    Sales_data(std::istream &);

    //接口，成员函数
    std::string isbn() const { return bookNo; }
    Sales_data &combine(const Sales_data &);
};

//Sales_data 的非成员接口函数声明
Sales_data add(const Sales_data &, Sales_data &);
std::ostream &print(std::ostream &, const Sales_data &);
std::istream &read(std::istream &, Sales_data &);

//构造函数定义
Sales_data::Sales_data(std::istream &is) {
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
