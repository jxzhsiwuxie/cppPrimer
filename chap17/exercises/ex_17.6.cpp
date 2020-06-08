//练习 17.6：重写 findBook，不适用 tuple 或 pair。

#include <algorithm>
#include <map>
#include <string>
#include <utility>
#include <vector>

using std::equal_range;
using std::map;
using std::pair;
using std::string;
using std::vector;

#include "../../chap16/exercises/Sales_data.h"


bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs) {
    return lhs.isbn() < rhs.isbn();
}

map<vector<Sales_data>::size_type, vector<Sales_data>> findBook(const vector<vector<Sales_data>> &files, const string &book) {
    map<vector<Sales_data>::size_type, vector<Sales_data>> ret;
    //对每家书店，查找与给定书籍匹配的记录范围（如果存在的话）
    for (auto it = files.cbegin(); it != files.cend(); ++it) {
        //查找具有相同 ISBN 的 Sales_data 范围
        auto found = equal_range(it->cbegin(), it->cend(), book, compareIsbn);

        if (found.first != found.second)
            ret[it - files.cbegin()] = vector<Sales_data>(found.first, found.second);
    }

    return ret;
}
