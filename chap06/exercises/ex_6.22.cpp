//练习 6.22：编写一个函数，令其交换两个 int 指针。

#include <iostream>

//使用指针的引用
void swapPtr(int *&, int *&);
//使用二阶指针
void swapPtr2(int **, int **);

int main() {
    int a = 20, b = 30, *pa = &a, *pb = &b;

    std::cout << "pa = " << pa << "; pb = " << pb << std::endl;
    std::cout << "*pa = " << *pa << "; *pb = " << *pb << std::endl;

    swapPtr(pa, pb);

    std::cout << "pa = " << pa << "; pb = " << pb << std::endl;
    std::cout << "*pa = " << *pa << "; *pb = " << *pb << std::endl;

    swapPtr2(&pa, &pb);

    std::cout << "pa = " << pa << "; pb = " << pb << std::endl;
    std::cout << "*pa = " << *pa << "; *pb = " << *pb << std::endl;

    return 0;
}

void swapPtr(int *&a, int *&b) {
    int *tmp;
    tmp = a;
    a = b;
    b = tmp;
}

void swapPtr2(int **a, int **b) {
    int *tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

