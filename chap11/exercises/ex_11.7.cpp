//练习 11.7：定义一个 map，关键字是家庭的姓，值是一个 vector，保存家中孩子（们）的名字。
//编写代码，实现添加新的家庭成员以及向已有家庭成员中添加新的孩子。

#include <cstddef>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::set;
using std::size_t;
using std::string;
using std::vector;

int main() {
    map<string, vector<string>> families;
    // families["zhang"] = {"zhang da", "zhang er", "zhang san"};

    char ch = 'y';
    string family_name, name;

    do {
        cout << "输入姓：";
        cin >> family_name;
        cout << "输入名：";
        cin >> name;

        if (families.find(family_name) != families.end())
            families[family_name].push_back(name);
        else
            families[family_name] = {name};

        cout << "是否继续输入（输入 y 继续，输入 q 退出）？";
    } while (cin >> ch && ch != 'q');

    cout << "当前所有的家庭为：" << endl;
    for (const auto &family : families) {
        cout << family.first << " 家的成员有：" << endl;
        for (const auto &name : family.second)
            cout << family.first << " " << name << ", ";
        cout << endl;
    }

    return 0;
}
