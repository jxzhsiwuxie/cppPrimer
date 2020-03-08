//练习 8.6：重写 7.1.1 节的书店程序（第 229 页），从一个文件中读取交易记录。将文件名作为一个参数传递给 main（参见 6.2.5 节，第 196 页）。

#include <fstream>
#include <iostream>
#include "Sales_data.h"

int main(int argc, char *argv[]) {
    using std::cin;
    using std::cout;
    using std::endl;
    using std::ifstream;

    if (argc < 2) {
        cout << "需要输入销售记录所在的文件" << endl;
        return 0;
    }

    char *path = argv[1];
    ifstream ifs(path);

    if (!ifs) {
        cout << "打开文件 " << path << " 失败" << endl;
        return 0;
    }

    Sales_data total;
    if (read(ifs, total)) {
        Sales_data trans;
        while (read(ifs, trans)) {
            if (total.isbn() == trans.isbn()) {
                total.combine(trans);
            } else {
                print(cout, total) << endl;
                total = trans;
            }
        }
        print(cout, total) << endl;
    } else {
        cout << "没有读取到数据" << endl;
    }

    return 0;
}
