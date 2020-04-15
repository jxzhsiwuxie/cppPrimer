//练习 11.32：使用上一题定义的 multimap 编写一个程序，按字典顺序打印作者列表和他们的作品。

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>

using std::cout;
using std::endl;
using std::map;
using std::multimap;
using std::set;
using std::sort;
using std::string;

int main() {
    multimap<string, string> authors;
    authors.insert({"zhangsan", "zhangsan c"});
    authors.insert({"zhangsan", "zhangsan a"});
    authors.insert({"zhangsan", "zhangsan b"});
    authors.insert({"lisi", "lisi c"});
    authors.insert({"lisi", "lisi a"});
    authors.insert({"lisi", "lisi b"});

    cout << "默认情况下的打印顺序：" << endl;
    for (const auto &item : authors)
        cout << item.first << " 著作：" << item.second << endl;
    cout << "-------------------------------" << endl;

    map<string, set<string>> order_authors;
    for (const auto &item : authors) {
        if (order_authors.count(item.first)) {
            order_authors.at(item.first).insert(item.second);
        } else {
            order_authors.insert({item.first, {item.second}});
        }
    }
    cout << "作者和著作都按照字典顺序的打印：" << endl;
    for (const auto &item : order_authors) {
        for (const auto &book : item.second)
            cout << item.first << " 著作：" << book << endl;
    }

    return 0;
}
