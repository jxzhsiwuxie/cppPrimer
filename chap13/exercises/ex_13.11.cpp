//练习 13.11：为前面练习中的 HasPtr 添加一个析构函数。

#include <iostream>
#include <string>

#include "HasPtr.h"

using std::cout;
using std::endl;
using std::string;

int main() {
    {
        HasPtr obj1("abc");
        HasPtr obj2;

        obj2 = obj1;

        std::cout << "原始情况 obj1 内容为：" << obj1.getString() << std::endl;
        std::cout << "原始情况 obj2 内容为：" << obj2.getString() << std::endl;

        obj1.updateString("a");
        std::cout << "obj1 被改变后 obj1 内容为：" << obj1.getString() << std::endl;
        std::cout << "obj1 被改变后 obj2 内容为：" << obj2.getString() << std::endl;
    }

    cout << "main 函数即将结束" << endl;

    return 0;
}
