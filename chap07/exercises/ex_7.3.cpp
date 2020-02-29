//练习 7.3：修改 7.1.1 节（第 229 页）的交易处理程序，令其使用这些成员。

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

int main() {
    Sales_data total;
    cout << "输入一组数据，每条数据（字符串 正整数 浮点数）例如： No12345 100 3.5" << endl;
    cout << "不同组数据数据之间用换行分隔：" << endl;

    if (cin >> total.bookNo >> total.units_solid >> total.revenue) {
        Sales_data trans;
        while (cin >> trans.bookNo >> trans.units_solid >> trans.revenue) {
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
