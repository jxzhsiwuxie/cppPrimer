#ifndef SALES_DATA_H_
#define SALES_DATA_H_

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
};

//Sales_data 的非成员接口函数声明
Sales_data add(const Sales_data &, Sales_data &);
std::ostream &print(std::ostream &, const Sales_data &);
std::istream &read(std::istream &, Sales_data &);

#endif