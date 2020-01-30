//练习 2.36：关于下面的代码，请指出每一个变量的类型以及程序结束时它们各自的值。
/*
* int a = 3, b = 4;
* decltype(a) c = a;
* decltype((b)) d = a;
* ++c;
* ++d;
*/

/*
* a 和 b 的类型都是 int。
* c 的类型是 int。
* d 的类型是 int &，并且绑定到对象 a 上。
* ++c 改变的是 c 本身的值，变为 4。
* ++d 改变的是引用的对象的值，也就是 a 的值，变为 4。
* 程序结束时，a 的值为 4，b 的值为 4，c 的值为 4，d 是变量 a 的引用，值就是 a 的值 4。
*/

#include <iostream>

int main()
{
    int a = 3, b = 4;
    decltype(a) c = a;
    decltype((b)) d = a;
    ++c;
    ++d;

    std::cout << "程序结束时各个变量的值：" << std::endl;
    std::cout << "a: " << a << ", ";
    std::cout << "b: " << b << ", ";
    std::cout << "c: " << c << ", ";
    std::cout << "d: " << d << std::endl;

    return 0;
}