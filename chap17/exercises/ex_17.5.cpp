//练习 17.5：重写 findBook，令其返回一个 pair，包含一个索引和一个迭代器 pair。

#include <algorithm>
#include <string>
#include <utility>
#include <vector>

using std::equal_range;
using std::pair;
using std::string;
using std::vector;

#include "../../chap16/exercises/Sales_data.h"

using matches = pair<vector<Sales_data>::size_type, pair<vector<Sales_data>::const_iterator, vector<Sales_data>::const_iterator>>;

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
            ret.push_back({it - files.cbegin(), found});
    }

    return ret;
}
