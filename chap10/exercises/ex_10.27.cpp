//练习 10.26：除了 unique 之外（参见 10.2.3 节，第 343 页）之外，标准库还定义了名为 unique_copy 的函数，
//它接受第三个迭代器，表示拷贝不重复元素的目的位置。编写一个程序，使用 unique_copy 将一个 vector 中不重复的元素拷贝到一个 list 中。

#include <algorithm>
#include <ctime>
#include <iostream>
#include <iterator>
#include <list>
#include <random>
#include <vector>

using std::cout;
using std::endl;
using std::list;
using std::vector;

using std::default_random_engine;
using std::normal_distribution;

int main() {
    default_random_engine e(std::time(NULL));
    normal_distribution<double> ndis(4, 2);

    vector<int> ivec;
    list<int> ilst;

    for (auto i = 0; i < 64; ++i)
        ivec.push_back(ndis(e));
    std::sort(ivec.begin(), ivec.end());

    cout << "vector 中的元素为：" << endl;
    for (const auto n : ivec)
        cout << n << " ";
    cout << endl;

    std::unique_copy(ivec.begin(), ivec.end(), std::inserter(ilst, ilst.begin()));
    cout << "经过 unique_copy 拷贝之后，list 中的元素为：" << endl;
    for (const auto n : ilst)
        cout << n << " ";
    cout << endl;

    return 0;
}
