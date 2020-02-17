//练习 6.11：编写并验证你自己的 reset 函数，使其作用于引用类型的参数。

#include <iostream>

void reset(int &i);

int main() {
    int n = 100;
    std::cout << "初始 n = " << n << std::endl;
    reset(n);
    std::cout << "调用 reset 函数之后，n = " << n << std::endl;
    return 0;
}

void reset(int &i) {
    i = 0;
}
