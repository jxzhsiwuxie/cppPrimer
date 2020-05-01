//练习 13.20：你的 Employee 类需要定义它自己的拷贝控制成员么？如果需要，为什么？
//如果不需要，为什么？实现你认为 Employee 需要的拷贝控制成员。

/*
* 需要拷贝控制成员，因为要求雇员号要求唯一，合成拷贝会直接复制雇员号。
* 实现拷贝构造函数和赋值构造函数即可。
*/

#include <iostream>

#include "Employee.h"

int main() {
    Employee e1, e2("zhangsan");

    std::cout << e1.getName() << ", " << e1.getId() << std::endl;
    std::cout << e2.getName() << ", " << e2.getId() << std::endl;
    std::cout << "-------------------------------" << std::endl;

    Employee e3 = e1, e4(e2);
    std::cout << e3.getName() << ", " << e3.getId() << std::endl;
    std::cout << e4.getName() << ", " << e4.getId() << std::endl;

    return 0;
}
