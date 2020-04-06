//练习 10.15：编写一个 lambda，捕获它所在函数的 int，接受一个 int 参数。lambda 应该返回捕获的 int 与 int 参数的和。

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
    int i = 123, val;

    cout << "输入一个整数：";
    if (cin >> val) {
        auto sum = [i](int a) -> int { return a + i; };
        cout << "利用 lambda 表达式计算的到 123 + " << val << " 的值为：" << sum(val) << endl;
    }

    return 0;
}
