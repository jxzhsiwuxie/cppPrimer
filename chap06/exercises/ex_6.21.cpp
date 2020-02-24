//练习 6.21：编写一个函数，令其接收两个参数：一个是 int 型的数，另一个是 int 型的指针。函数比较 int 型的值和指针所指的值，返回较大的那个。
//在该函数中，指针的类型应该是什么？

#include <iostream>

int intCompare(int a, int *b);

int main() {
    int a = 10, *b;
    *b = 20;

    std::cout << intCompare(a, b) << std::endl;

    return 0;
}

int intCompare(int a, int *b) {
    return a > *b ? a : *b;
}

// 指针的类型是 int。
