//练习 7.41：使用委托构造函数重新编写你的 Sales_data 类，给每个函数体添加一条语句，令其一旦执行就打印一条信息。
//用各种可能的方式创建 Sales_data 对象，认真研究每次输出的信息直到你确实理解了委托构造函数的执行顺序。

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
    Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), units_solid(n), revenue(n * p) { std::cout << "调用了 3 参数的构造函数" << std::endl; }
    Sales_data(const std::string &s) : Sales_data(s, 0, 0) { std::cout << "调用了只有一个 string 参数的构造函数" << std::endl; }
    Sales_data() : Sales_data("", 0, 0) { std::cout << "调用了默认构造函数" << std::endl; }
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

int main() {
    Sales_data item0;
    std::cout << "------------------------------------" << std::endl;

    Sales_data item1("1-22-333-4444-55555");
    std::cout << "------------------------------------" << std::endl;

    Sales_data item2("22-333-4444-55555-666666", 10, 2.3);
    std::cout << "------------------------------------" << std::endl;

    Sales_data item3(std::cin);

    return 0;
}
