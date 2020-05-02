//练习 13.31：为你的 HasPtr 类定义一个 < 运算符，并定义一个 HasPtr 的 vector。
//为这个 vector 添加一些元素，并对它执行 sort。注意何时会调用 swap。

#include <algorithm>
#include <iostream>
#include <vector>

#include "HasPtr.h"

using std::cout;
using std::endl;
using std::sort;
using std::vector;

int main() {
    vector<HasPtr> vec;
    vec.push_back(HasPtr("dadsa"));
    vec.push_back(HasPtr("gvdfgd"));
    vec.push_back(HasPtr("urtyrt"));
    vec.push_back(HasPtr("rwerwe"));
    vec.push_back(HasPtr("haetgar"));
    vec.push_back(HasPtr("rqr5q"));
    vec.push_back(HasPtr("AGFASGF"));
    vec.push_back(HasPtr("vXVvxvb"));
    vec.push_back(HasPtr("efsFFSD"));

    cout << "排序之前，vec 中元素内容为：" << endl;
    for (auto &item : vec)
        cout << item.getString() << " ";
    ;
    cout << endl;
    cout << "-----------------------------" << endl;

    sort(vec.begin(), vec.end());

    cout << "排序之后，vec 中元素内容为：" << endl;
    for (auto &item : vec)
        cout << item.getString() << " ";
    ;
    cout << endl;

    return 0;
}