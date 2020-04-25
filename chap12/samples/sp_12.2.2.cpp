//从标准输入中读取 n 个字符串，存到动态内存中

#include <cstddef>
#include <iostream>
#include <string>

using std::cin;
using std::size_t;
using std::string;

int main() {
    const size_t n = 100;
    string *const p = new string[n];
    string s;
    string *q = p;
    while (cin >> s)
        *q++ = s;

    const size_t size = q - p;
    delete[] p;

    return 0;
}
