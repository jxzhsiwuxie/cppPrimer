//练习 9.13：如何从一个 list<int> 初始化一个 vector<double>？从一个 vector<int> 又如何创建？编写代码验证你的答案。

/*
* 两个都只能通过传递迭代器范围的方式初始化。
*/

#include <iostream>
#include <list>
#include <vector>

using std::cout;
using std::endl;
using std::list;
using std::vector;

int main() {
    list<int> iList = {1, 3, 5, 7, 9};
    vector<int> iVector = {0, 2, 4, 6, 8};

    cout << "原始的 list<int> 内容为：" << endl;
    for (auto n : iList)
        cout << n << " ";
    cout << endl;

    cout << "原始的 vector<int> 内容为：" << endl;
    for (auto n : iVector)
        cout << n << " ";
    cout << endl;

    vector<double> dVector0(iList.begin(), iList.end());
    cout << "利用 list<int> 创建的 vector<double> 内容为：" << endl;
    for (auto n : dVector0)
        cout << n << " ";
    cout << endl;

    vector<double> dVector1(iVector.begin(), iVector.end());
    cout << "利用 vector<int> 创建的 vector<double> 内容为：" << endl;
    for (auto n : dVector1)
        cout << n << " ";
    cout << endl;

    return 0;
}
