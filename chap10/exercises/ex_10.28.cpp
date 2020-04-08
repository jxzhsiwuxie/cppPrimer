//练习 10.28：一个 vector 中保存 1 到 9，将其拷贝到其它桑菲容器中。分别使用 inserter、back_inserter 和 front_inserter 将元素添加到三个容器中。
//对每种 inserter，估计输出序列是怎样的，运行程序验证你的估计是否正确。

#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>

using std::back_inserter;
using std::copy;
using std::cout;
using std::endl;
using std::front_inserter;
using std::inserter;
using std::list;
using std::vector;

int main() {
    vector<int> ivec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    list<int> iiList, ibList, ifList;

    copy(ivec.begin(), ivec.end(), inserter(iiList, iiList.begin()));
    copy(ivec.begin(), ivec.end(), back_inserter(ibList));
    copy(ivec.begin(), ivec.end(), front_inserter(ifList));

    cout << "原始的 vector 的内容为：" << endl;
    for (const auto n : ivec)
        cout << n << " ";
    cout << endl;
    cout << "-----------------------------" << endl;

    cout << "使用 inserter 得到的结果为：" << endl;
    for (const auto n : iiList)
        cout << n << " ";
    cout << endl;
    cout << "-----------------------------" << endl;

    cout << "使用 back_inserter 得到的结果为：" << endl;
    for (const auto n : ibList)
        cout << n << " ";
    cout << endl;
    cout << "-----------------------------" << endl;

    cout << "使用 front_inserter 得到的结果为：" << endl;
    for (const auto n : ifList)
        cout << n << " ";
    cout << endl;
    cout << "-----------------------------"<<endl;

    return 0;
}
