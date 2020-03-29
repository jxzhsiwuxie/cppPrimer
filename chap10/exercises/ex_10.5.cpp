//练习 10.5：在本节对名册（roster）调用 equal 的例子中，如果两个名册中保存的都是 C 风格字符串而不是 string，会发生什么？

/*
* C 风格字符串的类型即 const char*，表示的是指向常量字符的指针，直接利用 == 比较它们没有意义，得到的结果应该是不确定的。
* 但是实际上在当前环境下确实可以正确的工作，比较奇怪。
*/

#include <iostream>

int main() {
    const char *s1 = "abcd", *s2 = "abcd";

    std::cout << (s1 == s2) << std::endl;

    return 0;
}
