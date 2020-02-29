//练习 7.1：使用 2.6.1 节练习定义的 Sales_data 类为 1.6 节（第 21 页）的交易处理程序编写一个新的程序。

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

struct Sales_data {
    string bookNo;                 //书籍 ISBN 号
    unsigned int units_solid = 0;  //销售数量
    double revenue = 0.0;          //销售收入
};

int main() {
    Sales_data total;
    cout << "输入一组数据，每条数据（字符串 正整数 浮点数）例如： No12345 100 3.5" << endl;
    cout << "不同组数据数据之间用换行分隔：" << endl;

    if (cin >> total.bookNo >> total.units_solid >> total.revenue) {
        Sales_data trans;
        while (cin >> trans.bookNo >> trans.units_solid >> trans.revenue) {
            if (total.bookNo == trans.bookNo) {
                total.units_solid += trans.units_solid;
                total.revenue += trans.revenue;
            } else {
                cout << "ISBN 为 " << total.bookNo << " 的书籍共销售 " << total.units_solid << " 本，总销售额为￥ " << total.revenue << endl;
                total = trans;
            }
        }
        cout << "ISBN 为 " << total.bookNo << " 的书籍共销售 " << total.units_solid << " 本，总销售额为￥ " << total.revenue << endl;
    } else {
        cout << "没有读取到正确数据" << endl;
    }

    return 0;
}
