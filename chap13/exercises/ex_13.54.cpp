//练习 13.54：如果我们为 HasPtr 定义移动赋值运算符，但未改变拷贝交换运算符，会发什么？编写代码验证你的答案。

/*
* 改变拷贝交换运算符？没看懂。
*/

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
