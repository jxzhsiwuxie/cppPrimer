//练习 11.31：编写程序，定义一个作者及其作品的 multimap。使用 find 在 multimap 中查找一个元素并用 erase 删除它。
//确保你的程序在元素不在 map 中也能正常运行。

#include <iostream>
#include <map>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::multimap;
using std::string;

int main() {
    multimap<string, string> authors;
    authors.insert({"zhangsan", "zhangsan c"});
    authors.insert({"zhangsan", "zhangsan a"});
    authors.insert({"zhangsan", "zhangsan b"});
    authors.insert({"lisi", "lisi c"});
    authors.insert({"lisi", "lisi a"});
    authors.insert({"lisi", "lisi b"});

    for (const auto &item : authors)
        cout << item.first << " 著作：" << item.second << endl;

    string name;
    cout << "输入你想删除谁的著作：";

    if (cin >> name) {
        auto it = authors.find(name);
        if (it != authors.end()) {
            authors.erase(it);

            cout << "删除之后：" << endl;
            for (const auto &item : authors)
                cout << item.first << " 著作：" << item.second << endl;
        } else {
            cout << "没有这个作者" << endl;
        }
    }

    return 0;
}
