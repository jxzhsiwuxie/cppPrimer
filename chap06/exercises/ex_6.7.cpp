//练习 6.7：编写一个函数，当它第一次被调用时返回 0，以后每次被调用返回值加 1。

#include <cstddef>
#include <iostream>

size_t count_calls() {
    static size_t ctr = 0;
    return ++ctr;
}

int main() {
    for (size_t i = 0; i != 10; i++) {
        std::cout << count_calls() << std::endl;
    }
    return 0;
}
