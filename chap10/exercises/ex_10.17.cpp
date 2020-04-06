//练习 10.17：重写 10.3.1 节练习 10.12（第 345 页）的程序，在对 sort 的调用中使用 lambda 来替代 compareIsbn。

#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

#include "Sales_data.h"

using std::cout;
;
using std::endl;
using std::ifstream;
using std::vector;

int main() {
    ifstream ifs;
    ifs.open("sales.txt");

    vector<Sales_data> items;
    Sales_data tmpItem;
    while (read(ifs, tmpItem))
        items.push_back(tmpItem);

    cout << "原本 vector 中含有的 Sales_data 为：" << endl;
    for (const auto &item : items) {
        print(cout, item);
        cout << endl;
    }
    cout << "---------------------------------------" << endl;

    std::sort(items.begin(), items.end(), [](const Sales_data &item1, const Sales_data &item2) -> bool {
        return item1.isbn() < item2.isbn();
    });

    cout << "经过排序后 vector 中含有的 Sales_data 为：" << endl;
    for (const auto &item : items) {
        print(cout, item);
        cout << endl;
    }

    return 0;
}
