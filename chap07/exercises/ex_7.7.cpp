//练习 7.7：使用这些新函数重写 7.1.2 节（第 233 页）练习中的交易处理程序。

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

Sales_data add(const Sales_data &, Sales_data &);
std::ostream &print(std::ostream &, const Sales_data &);
std::istream &read(std::istream &, Sales_data &);

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

Sales_data add(const Sales_data &lhs, Sales_data &rhs) {
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

std::istream &read(std::istream &is, Sales_data &item) {
    double price = 0;
    is >> item.bookNo >> item.units_solid >> price;
    item.revenue = item.units_solid * price;

    return is;
}

std::ostream &print(std::ostream &os, const Sales_data &item) {
    os << item.isbn() << " " << item.units_solid << " "
       << item.revenue << " " << item.avg_price();

    return os;
}

/*------------------------------------------------------------------------------*/

int main() {
    Sales_data total;
    double price = 0;
    cout << "输入一组数据，每条数据（字符串 正整数 浮点数）例如： No12345 100 3.5" << endl;
    cout << "不同组数据数据之间用换行分隔：" << endl;

    if (read(cin, total)) {
        Sales_data trans;
        while (read(cin, trans)) {
            if (total.isbn() == trans.isbn()) {
                total.combine(trans);
            } else {
                cout << "ISBN 为 " << total.isbn() << " 的书籍共销售 " << total.units_solid << " 本，总销售额为￥ " << total.revenue << endl;
                total = trans;
            }
        }
        cout << "ISBN 为 " << total.isbn() << " 的书籍共销售 " << total.units_solid << " 本，总销售额为￥ " << total.revenue << endl;
    } else {
        cout << "没有读取到正确数据" << endl;
    }

    return 0;
}
