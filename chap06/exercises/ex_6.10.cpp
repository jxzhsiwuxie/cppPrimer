//练习 6.10：编写一个函数，使用指针形参交换两个整数的值。在代码中调用该函数并输出交换后的值，建议使用引用类型的形参代替指针。

#include <iostream>

void swapByPtr(int *ptr1, int *ptr2);
void swapByRef(int &n1, int &n2);

int main() {
    int n1 = 1, n2 = 2, n3 = 3, n4 = 4;
    std::cout << "交换之前 n1 = " << n1 << "，n2 = " << n2 << std::endl;
    std::cout << "交换之前 n3 = " << n3 << "，n4 = " << n4 << std::endl;

    swapByPtr(&n1, &n2);
    std::cout << "利用指针交换之后 n1 = " << n1 << "，n2 = " << n2 << std::endl;

    swapByRef(n3, n4);
    std::cout << "利用引用交换之后 n3 = " << n3 << "，n4 = " << n4 << std::endl;

    return 0;
}

void swapByPtr(int *ptr1, int *ptr2) {
    int tmp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = tmp;
}

void swapByRef(int &n1, int &n2) {
    int tmp = n1;
    n1 = n2;
    n2 = tmp;
}
