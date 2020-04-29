//练习 13.8：为 13.1.1 节（第 43 页）练习 13.5 中的 HasPtr 类编写拷贝赋值运算符。
//类似拷贝构造函数，你的赋值运算符应该将对象拷贝到 ps 指向的位置。

#include <iostream>
#include <string>

#include "HasPtr.h"

using std::cout;
using std::endl;
using std::string;

int main() {
    HasPtr obj1("abc");
    HasPtr obj2;

    obj2 = obj1;

    std::cout << "原始情况 obj1 内容为：" << obj1.getString() << std::endl;
    std::cout << "原始情况 obj2 内容为：" << obj2.getString() << std::endl;

    obj1.updateString("a");
    std::cout << "obj1 被改变后 obj1 内容为：" << obj1.getString() << std::endl;
    std::cout << "obj1 被改变后 obj2 内容为：" << obj2.getString() << std::endl;

    return 0;
}
