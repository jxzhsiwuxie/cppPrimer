//练习 11.14：扩展你在 11.2.1 节（第 378 页）中编写的孩子姓名的 map，添加一个 pair 的 vector，保存孩子的名和生日。

#include <cstddef>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::make_pair;
using std::map;
using std::pair;
using std::set;
using std::size_t;
using std::string;
using std::vector;

int main() {
    map<string, vector<pair<string, string>>> families;

    char ch = 'y';
    string family_name, name, birthday;

    do {
        cout << "输入姓：";
        cin >> family_name;
        cout << "输入名：";
        cin >> name;
        cout << "输入生日：";
        cin >> birthday;

        if (families.find(family_name) != families.end())
            families[family_name].push_back({name, birthday});
        else
            families[family_name] = {make_pair(name, birthday)};

        cout << "是否继续输入（输入 y 继续，输入 q 退出）？";
    } while (cin >> ch && ch != 'q');

    cout << "当前所有的家庭为：" << endl;
    for (const auto &family : families) {
        cout << family.first << " 家的成员有：" << endl;
        for (const auto &name_birth : family.second)
            cout << family.first << " " << name_birth.first << "  生日：" << name_birth.second << "， ";
        cout << endl;
    }

    return 0;
}
