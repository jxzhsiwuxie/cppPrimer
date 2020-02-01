//练习 3.42：编写一段程序，将含有整型元素的 vector 对象拷贝给一个整型数组。

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main()
{
    const vector<int> ivec = {0, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    const std::size_t len = 11;
    int ia[len];

    for (std::size_t i = 0; i < len; i++)
        ia[i] = ivec[i];

    cout << "vector 中元素为：" << endl;
    for (auto n : ivec)
        cout << n << " ";
    cout << endl;

    cout << "数组中元素为：" << endl;
    for (auto n : ia)
        cout << n << " ";
    cout << endl;

    return 0;
}