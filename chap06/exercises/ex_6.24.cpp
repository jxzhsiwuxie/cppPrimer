//练习 6.24：描述下面这个函数的行为。如果代码中有问题，请指出并改正。
// void print (const int ia[10]) {
//     for (size_t i = 0; i != 10; ++i)
//         cout << ia[i] << endl;
// }

/*
* 函数希望遍历一个包含 10 个整数的数组并打印每一个元素。
* 对于数组形参，函数会忽略数组的第一个维度，所以形参中传入的 10 并没有意义，
* 在实际调用函数的过程中并不能约束作为实参传入的数组的维度。
* 可修改为：
*/
// void print (const int (&ia)[10]) {
//     for (size_t i = 0; i != 10; ++i)
//         cout << ia[i] << endl;
// }

#include <cstddef>
#include <iostream>

using std::cout;
using std::endl;
using std::size_t;

void print(const int (&ia)[10]) {
    for (size_t i = 0; i != 10; ++i)
        cout << ia[i] << endl;
}

int main() {
    int a1[] = {11, 2, 3, 4}, a2[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    // print(a1);   //错误

    print(a2);

    return 0;
}
