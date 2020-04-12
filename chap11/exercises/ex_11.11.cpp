//练习 11.11：不适用 decltype 重新定义 bookstore。

#include <iostream>
#include <map>

#include "Sales_data.h"

using std::map;
using std::multimap;

bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs) {
    return lhs.isbn() < rhs.isbn();
}

int main() {
    auto *fun_ptr0 = compareIsbn;
    bool (*fun_ptr)(const Sales_data &, const Sales_data &) = compareIsbn;
    std::cout << (fun_ptr0 == fun_ptr) << std::endl;

    using FUNC = bool (*)(const Sales_data &, const Sales_data &);

    multimap<Sales_data, FUNC> bookstore(FUNC);

    return 0;
}
