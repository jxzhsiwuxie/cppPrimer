//练习 10.36：使用 find 在一个 int 的 list 中查找最后一个值为 0 的中元素。

#include <algorithm>
#include <ctime>
#include <iostream>
#include <list>
#include <random>

using std::cout;
using std::endl;
using std::list;

using std::find;

using std::default_random_engine;
using std::normal_distribution;

int main() {
    default_random_engine e(std::time(NULL));
    normal_distribution<double> ndis(0, 4);
    list<int> ilst;

    for (int i = 0; i < 10; ++i)
        ilst.push_back(ndis(e));

    for (const auto n : ilst)
        cout << n << " ";
    cout << endl;

    auto it = find(ilst.crbegin(), ilst.crend(), 0);
    if (it != ilst.crend()) {
        cout << "最后一个 0 前面一个元素为 " << *(++it) << endl;
    } else {
        cout << "list 中没有 0" << endl;
    }

    return 0;
}