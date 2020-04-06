//练习 10.14：编写一个 lambda，接受两个 int，返回它们的和。

#include <iostream>

using std::cout;
using std::endl;

auto sum = [](int a, int b) -> int { return a + b; };

int main() {
    cout << "利用 lambda 表达式计算的到 123 + 456 的值为：" << sum(123, 456) << endl;

    return 0;
}
