//练习 13.18：：定义一个 Employee 类，它包含雇员的姓名和唯一的雇员证号。为这个类定义默认构造函数，以及接受一个表示雇员姓名的 string 构造函数。
//每个构造函数应该通过传递一个 static 数据成员类来生成一个唯一的证号。

#include <iostream>
#include "Employee.h"


int main() {
    Employee e1, e2("zhangsan");

    std::cout << e1.getName() << ", " << e1.getId() << std::endl;
    std::cout << e2.getName() << ", " << e2.getId() << std::endl;
    return 0;
}
