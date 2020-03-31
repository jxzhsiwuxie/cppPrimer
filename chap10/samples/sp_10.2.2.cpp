//利用拷贝算法复制内置数组的元素

#include <iostream>
#include <iterator>

using std::cout;
using std::endl;

int main() {
    int a1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int a2[sizeof(a1) / sizeof(*a1)];

    cout << "数组 a1 中的元素为：" << endl;
    for (const auto n : a1)
        cout << n << " ";
    cout << endl;

    std::copy(std::crbegin(a1), std::crend(a1), a2);

    cout << "经过拷贝后数组 a2 中的元素为：" << endl;
    for (const auto n : a2)
        cout << n << " ";
    cout << endl;

    return 0;
}
