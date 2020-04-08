//练习 10.32：重写 1.6 节（第 21 页）中的书店程序，使用一个 vector 保存交易记录，使用不同算法完成处理。
//使用 sort 和 10.3.1 节（第 345 页） 中的 compareIsbn 函数来排序交易记录，然后使用 find 和 accumulate 求和。

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

#include "Sales_item.h"

using std::cout;
using std::endl;
using std::ifstream;
using std::istream_iterator;
using std::ostream_iterator;
using std::vector;

using std::accumulate;
using std::copy;
using std::find;
using std::find_if;
using std::for_each;
using std::sort;

bool compareIsbn(const Sales_item &item1, const Sales_item &item2) {
    return item1.isbn() < item2.isbn();
}

//这里使用了 find_if 而不是 find，因为使用 find 搞不定。。。
int main() {
    ifstream ifs("sales.txt");
    vector<Sales_item> items;

    ostream_iterator<Sales_item> out(cout, "\n");
    istream_iterator<Sales_item> in(ifs), eof;
    while (in != eof)
        items.push_back(*in++);

    sort(items.begin(), items.end(), compareIsbn);

    cout << "经过排序之后所有的记录为：" << endl;
    for_each(items.cbegin(), items.cend(), [](const Sales_item &item) {
        cout << item << endl;
    });
    cout << "------------------------------------" << endl;

    cout << "经过统计之后各个记录为：" << endl;
    auto beg = items.begin(), end = items.end();
    while (beg != end) {
        auto itFirst = find_if(beg, end, [&](const Sales_item &item) { return beg->isbn() == item.isbn(); });
        auto itLast = find_if(beg, end, [&](const Sales_item &item) { return beg->isbn() != item.isbn(); });
        auto total = accumulate(itFirst, itLast, Sales_item(itFirst->isbn()));
        //cout << total << endl;
        *out++ = total;

        beg = itLast;
    }

    return 0;
}