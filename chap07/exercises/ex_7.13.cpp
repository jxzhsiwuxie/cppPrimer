//练习 7.13：利用 istream 构造函数重写第 229 页的程序。

#include <iostream>
#include <string>

//前置声明，不然 Sales_data 内部无法使用 read 函数。
struct Sales_data;

//Sales_data 的非成员接口函数
Sales_data add(const Sales_data &, Sales_data &);
std::ostream &print(std::ostream &, const Sales_data &);
std::istream &read(std::istream &, Sales_data &);

struct Sales_data {
    //数据成员
    std::string bookNo;            //书籍 ISBN 号
    unsigned int units_solid = 0;  //销售数量
    double revenue = 0.0;          //销售收入

    //构造函数
    Sales_data() = default;
    Sales_data(const std::string &s) : bookNo(s){};
    Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), units_solid(n), revenue(n * p) {}
    Sales_data(std::istream &is) { read(is, *this); }

    //成员函数
    std::string isbn() const { return bookNo; }
    Sales_data &combine(const Sales_data &);
    double avg_price() const;
};

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

using std::cerr;
using std::cin;
using std::cout;
using std::endl;

int main() {
    Sales_data total(cin);
    if (cin) {
        Sales_data trans(cin);
        while (cin) {
            if (total.isbn() == trans.isbn()) {
                total.combine(trans);
            } else {
                print(cout, total) << endl;
                total = trans;
            }
            read(cin, trans);
        }
        print(cout, total) << endl;

    } else {
        cerr << "没有获取到正确数据" << endl;
    }

    return 0;
}
