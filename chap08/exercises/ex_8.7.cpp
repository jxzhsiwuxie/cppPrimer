//练习 8.7：修改上一节的书店程序。将结果保存到一个文件中。将输出文件名作为第二个参数传递给 main 函数。

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
    ofstream ofs(outPath);

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
