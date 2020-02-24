//练习 6.27：编写一个函数，它的参数是 initializer_list<int> 类型的对象，函数的功能是计算列表中所有元素的和。

#include <initializer_list>
#include <iostream>

using std::cout;
using std::endl;
using std::initializer_list;

int listSum(initializer_list<int> il);

int main() {
    initializer_list<int> il = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << "列表中所有元素的和为：" << listSum(il) << endl;

    return 0;
}

int listSum(initializer_list<int> il) {
    int sum = 0;
    for (const auto &n : il)
        sum += n;
    return sum;
}
