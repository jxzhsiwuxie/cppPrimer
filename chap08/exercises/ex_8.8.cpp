//练习 8.8：修改上一题的程序，将结果追加到给定的文件末尾。对同一个输出文件，运行程序至少两次，检查数据是否得以保留。

#include <fstream>
#include <iostream>
#include "Sales_data.h"

int main(int argc, char *argv[]) {
    using std::cin;
    using std::cout;
    using std::endl;
    using std::ifstream;
    using std::ofstream;

    if (argc < 3) {
        cout << "需要输入销售记录所在的文件以及保存文件的名字" << endl;
        return 0;
    }

    char *inPath = argv[1], *outPath = argv[2];
    ifstream ifs(inPath);
    ofstream ofs(outPath, ofstream::app);

    if (!ifs) {
        cout << "打开文件 " << inPath << " 失败" << endl;
        return 0;
    }
    if (!ofs) {
        cout << "打开文件 " << outPath << " 失败" << endl;
        return 0;
    }

    ofs << "sales data output:" << endl;
    Sales_data total;
    if (read(ifs, total)) {
        Sales_data trans;
        while (read(ifs, trans)) {
            if (total.isbn() == trans.isbn()) {
                total.combine(trans);
            } else {
                print(ofs, total) << endl;
                total = trans;
            }
        }
        print(ofs, total) << endl;
    } else {
        cout << "没有读取到数据" << endl;
    }

    return 0;
}
