//练习 6.12：改写 6.2.1 节中练习 6.10 的程序，使用引用而非指针交换两个整数的值。你觉得哪种方法更易于使用呢？为什么？


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


/*
* 显然使用引用参数更加方便使用。
* 一方面在定义函数时，函数内部不需要像使用指针那样进行解引用的额外操作；
* 另一方面，在调用函数的时候，只需要传入变量本身就可以，不需要像使用指针那样传入变量的地址。
*/
