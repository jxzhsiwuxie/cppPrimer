//练习 10.12：编写名为 compareIsbn 的函数，比较两个 Sales_data 对象的 isbn() 成员。
//使用这个函数排序一个保存 Sales_data 对象的 vector。

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

bool compareIsbn(const Sales_data &, const Sales_data &);

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

    std::sort(items.begin(), items.end(), compareIsbn);
    cout << "经过排序后 vector 中含有的 Sales_data 为：" << endl;
    for (const auto &item : items) {
        print(cout, item);
        cout << endl;
    }

    return 0;
}

bool compareIsbn(const Sales_data &item1, const Sales_data &item2) {
    return item1.isbn() < item2.isbn();
}
