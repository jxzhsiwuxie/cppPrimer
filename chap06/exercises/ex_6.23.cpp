//练习 6.23：参考本节介绍的几个 print 函数，根据理解编写你自己的版本。
//依次调用每个函数使其输入下面定义的 i 和 j。
// int i = 0, j[2] = {0, 1};

#include <cstddef>
#include <iostream>

void print(int *arr, std::size_t n);

void print(int *begin, int *end);

int main() {
    int i = 0, j[2] = {0, 1};

    print(&i, 1);
    print(j, 2);

    std::cout << "--------------------------" << std::endl;

    print(&i, &i + 1);
    print(std::begin(j), std::end(j));

    return 0;
}

void print(int *arr, std::size_t n) {
    for (std::size_t i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
}

void print(int *begin, int *end) {
    while (begin != end) {
        std::cout << *begin++ << " ";
    }

    std::cout << std::endl;
}
