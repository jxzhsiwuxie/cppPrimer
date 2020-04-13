//练习 11.19：定义一个变量，通过 11.2.2 节（第 378 页）中的名为 bookstore 的 multiset 调用 begin() 来初始化这个变量。
//写出变量的类型，不要用 auto 或者 decltype。

#include <iostream>
#include <iterator>
#include <set>

#include "Sales_data.h"

using std::inserter;
using std::multiset;

bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs) {
    return lhs.isbn() < rhs.isbn();
}

int main() {
    using FUNC = bool (*)(const Sales_data &, const Sales_data &);

    multiset<Sales_data, FUNC> bookstore(compareIsbn);
    multiset<Sales_data, FUNC>::iterator it = bookstore.begin();
    inserter(bookstore, bookstore.begin()) = Sales_data("book-2020-04-13");

    print(std::cout, *(bookstore.begin()));

    return 0;
}