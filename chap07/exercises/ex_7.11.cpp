//练习 7.11：在你的 Sales_data 类中添加构造函数，然后编写一段程序令其用到每个构造函数。

#include <iostream>
#include <string>

struct Sales_data {
    //数据成员
    std::string bookNo;            //书籍 ISBN 号
    unsigned int units_solid = 0;  //销售数量
    double revenue = 0.0;          //销售收入

    //构造函数
    Sales_data() = default;
    Sales_data(const std::string &s) : bookNo(s){};
    Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), units_solid(n), revenue(n * p) {}
    Sales_data(std::istream &);

    //成员函数
    std::string isbn() const { return bookNo; }
    Sales_data &combine(const Sales_data &);
    double avg_price() const;
};

//Sales_data 的非成员接口函数
Sales_data add(const Sales_data &, Sales_data &);
std::ostream &print(std::ostream &, const Sales_data &);
std::istream &read(std::istream &, Sales_data &);

//构造函数定义
Sales_data::Sales_data(std::istream &is) {
    read(is, *this);
}

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

using std::cin;
using std::cout;
using std::endl;

int main() {
    //使用默认构造函数
    Sales_data item0;
    cout << "使用默认构造函数得到的数据为：" << endl;
    cout << "ISBN：" << item0.isbn() << "，销售数量为：" << item0.units_solid << "，销售总额为：￥" << item0.revenue << endl;
    cout << "------------------------------------------" << endl;

    //使用 Sales_data(const std::string &) 构造函数
    std::string bookNo1;
    cout << "输入一个 ISBN：";
    if (cin >> bookNo1) {
        Sales_data item1(bookNo1);
        cout << "使用一个常量字符串的构造函数得到的数据为：" << endl;
        cout << "ISBN：" << item1.isbn() << "，销售数量为：" << item1.units_solid << "，销售总额为：￥" << item1.revenue << endl;
        cout << "------------------------------------------" << endl;
    }

    //使用 Sales_data(const std::string &, unsigned, double) 构造函数
    cout << "输入一条数据（isbn 销售数量 单价）" << endl;
    std::string bookNo2;
    unsigned num2;
    double price2;
    if (cin >> bookNo2 >> num2 >> price2) {
        Sales_data item2(bookNo2, num2, price2);
        cout << "使用一个三个参数的构造函数得到的数据为：" << endl;
        cout << "ISBN：" << item2.isbn() << "，销售数量为：" << item2.units_solid << "，销售总额为：￥" << item2.revenue << endl;
        cout << "------------------------------------------" << endl;
    }

    //使用 Sales_data(std::istream &) 构造函数
    cout << "输入一条数据（isbn 销售数量 单价）" << endl;
    Sales_data item3(cin);
    if (cin) {
        cout << "使用一个标准输入参数的构造函数得到的数据为：" << endl;
        cout << "ISBN：" << item3.isbn() << "，销售数量为：" << item3.units_solid << "，销售总额为：￥" << item3.revenue << endl;
    }

    return 0;
}
