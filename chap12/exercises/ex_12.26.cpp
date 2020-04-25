//练习 12.26：用 allocator 重写第 427 页中的程序。

#include <cstddef>
#include <iostream>
#include <memory>
#include <string>

using std::allocator;
using std::cin;
using std::size_t;
using std::string;

int main() {
    const size_t n = 100;
    allocator<string> alloc;
    string *const p = alloc.allocate(n);

    string s;
    string *q = p;

    std::cout << "输入一行文字：" << std::endl;
    while (cin >> s)
        alloc.construct(q++, s);

    size_t size = q - p;
    for (size_t i = 0; i < size; ++i)
        std::cout << *(p + i) << " ";
    std::cout << std::endl;

    while (q != p)
        alloc.destroy(--q);

    alloc.deallocate(p, n);

    return 0;
}
