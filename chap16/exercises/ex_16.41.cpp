//练习 16.41：编写一个新的 sum 版本，它的返回类型保证足够大，足以容纳加法结果。

#include <iostream>

template <typename T>
auto sum(T t1, T t2) -> decltype(t1 + t2) {
    return t1 + t2;
}

int main() {
    auto res = sum(2147483647, 1);

    std::cout << res << std::endl;

    std::cout << INT_MAX << std::endl;

    return 0;
}

/*
* 这样并不行，所以想不到如何做。
*/
