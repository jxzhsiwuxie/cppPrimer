//练习 16.7：编写一个 constexpr 模板，返回给定数组的大小。

#include <iostream>

template <typename T, unsigned n>
constexpr unsigned getArrSize(T (&arr)[n]) {
    return n;
}

int main() {
    double arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    std::cout << getArrSize(arr) << std::endl;

    return 0;
}
