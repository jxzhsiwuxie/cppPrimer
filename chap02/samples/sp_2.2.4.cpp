//作用域中一旦声明了某个名字，它所嵌套着的所有作用域中都能访问该名字。
//同时允许在内层作用域中重新定义外层作用域已有的名字。

#include <iostream>

int reused = 42; //reused 拥有全局作用域

int main()
{
    int unique = 0; //unique 拥有块级作用域
    //输出#1：使用全局变量 reused；输出 42 0
    std::cout << reused << " " << unique << std::endl;

    int reused = 0; //新建局部变量 reused，覆盖了全局变量 reused
    //输出#2：使用局部变量 reused；输出 0 0
    std::cout << reused << " " << unique << std::endl;

    //输出#3：显式地访问全局变量 reused；输出 42 0
    std::cout << ::reused << " " << unique << std::endl;

    return 0;
}