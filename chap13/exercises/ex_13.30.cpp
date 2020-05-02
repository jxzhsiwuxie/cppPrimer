//练习 13.30：为你的类值版本的 HasPtr 编写 swap 函数，并测试它。为你的 swap 函数添加一个打印语句，指出函数什么时候执行。

#include <iostream>

#include "HasPtr.h"

int main() {
    HasPtr p1("张三");
    HasPtr p2("李四");

    std::cout << "交换之前 p1 内容为：" << p1.getString() << "，p2 内容为：" << p2.getString() << std::endl;
    swap(p1, p2);
    std::cout << "交换之后 p1 内容为：" << p1.getString() << "，p2 内容为：" << p2.getString() << std::endl;

    return 0;
}
