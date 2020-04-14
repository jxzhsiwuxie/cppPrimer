//练习 11.23：11.2.1 节练习（第 378 页）中的 map 以孩子的姓为关键字，保存他们的名字的 vector，用 multimap 重写此 map。

#include <cstddef>
#include <iostream>
#include <map>
#include <set>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::multimap;
using std::set;
using std::size_t;
using std::string;

int main() {
    multimap<string, string> families;

    char ch = 'y';
    string family_name, name;

    do {
        cout << "输入姓：";
        cin >> family_name;
        cout << "输入名：";
        cin >> name;

        families.insert({family_name, name});

        cout << "是否继续输入（输入 y 继续，输入 q 退出）？";
    } while (cin >> ch && ch != 'q');

    cout << "当前所有的家庭为：" << endl;
    for (const auto &family : families) {
        cout << family.first << " " << family.second <<  endl;
    }

    return 0;
}
