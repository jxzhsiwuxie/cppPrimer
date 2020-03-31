//练习 10.6：编写程序，使用 fill_n 将一个序列中的 int 值豆豆设为 0。

#include <iostream>
#include <iterator>
#include <vector>

using std::back_inserter;
using std::cout;
using std::endl;
using std::fill_n;
using std::vector;

int main() {
    vector<int> ivec;
    cout << "初始时，ivec 中 元素个数为：" << ivec.size() << endl;

    fill_n(back_inserter(ivec), 10, 0);

    cout << "利用 fill_n 算法填充之后，ivec 中元素个数为：" << ivec.size() << "，分别为：" << endl;
    for (const auto n : ivec)
        cout << n << " ";
    cout << endl;

    return 0;
}
