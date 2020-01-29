//练习 2.1：编写代码分别更改指针的值以及指针所指对象的值。

#include <iostream>

int main()
{
    int i = 0, j = 1, *ptr = &i;

    std::cout << "当前 ptr 的值为：" << (void *)ptr << std::endl;
    std::cout << "当前 ptr 所指对象的值为：" << *ptr << std::endl;

    //修改指针的值
    ptr = &j;
    std::cout << "当前 ptr 的值为：" << (void *)ptr << std::endl;
    std::cout << "当前 ptr 所指对象的值为：" << *ptr << std::endl;

    //修改指针所指对象的值
    *ptr = 2;
    std::cout << "当前 ptr 的值为：" << (void *)ptr << std::endl;
    std::cout << "当前 ptr 所指对象的值为：" << *ptr << std::endl;

    return 0;
}