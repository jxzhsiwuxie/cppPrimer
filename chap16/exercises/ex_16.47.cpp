//练习 16.47：编写你自己版本的翻转函数，通过调用接受左值和右值引用参数的函数来测试它。

#include <iostream>
#include <utility>

using std::cout;
using std::endl;

template <typename F, typename T1, typename T2>
void flip(F f, T1&& t1, T2&& t2) {
    f(std::forward<T2>(t2), std::forward<T1>(t1));
}

void func(int& n, int&& m) {
    ++n;
    cout << m + 1 << endl;
}

int main() {
    int i = 1;

    flip(func, 99, i);
    cout << i << endl;

    return 0;
}
