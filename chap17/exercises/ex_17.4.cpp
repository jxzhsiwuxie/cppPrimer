//练习 17.4：编写并测试你自己版本的 findBook 函数。

#include <algorithm>
#include <string>
#include <tuple>
#include <vector>

using std::equal_range;
using std::string;
using std::tuple;
using std::vector;

#include "../../chap16/exercises/Sales_data.h"

typedef tuple<vector<Sales_data>::size_type, vector<Sales_data>::const_iterator, vector<Sales_data>::const_iterator> matches;

bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs) {
    return lhs.isbn() < rhs.isbn();
}

vector<matches> findBook(const vector<vector<Sales_data>> &files, const string &book) {
    vector<matches> ret;  //初始化为空 vector
    //对每家书店，查找与给定书籍匹配的记录范围（如果存在的话）
    for (auto it = files.cbegin(); it != files.cend(); ++it) {
        //查找具有相同 ISBN 的 Sales_data 范围
        auto found = equal_range(it->cbegin(), it->cend(), book, compareIsbn);

        if (found.first != found.second)
            ret.push_back(std::make_tuple(it - files.cbegin(), found.first, found.second));
    }

    return ret;
}
