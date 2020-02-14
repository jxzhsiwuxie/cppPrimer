//练习 6.9：编写尼自己的 fact.cc 和 factMain.cc，这两个文件都应该包含上一小节练习中编写的 Chapter6.h 头文件。
///通过这些文件，理解你的编译器是如何支持分离式编译的。

#include <iostream>
#include "Chapter6.h"

using std::cin;
using std::cout;
using std::endl;

int main() {
    int val = 0;
    cout << "输入一个正整数：";
    if (cin >> val && val >= 0) {
        cout << val << "! = " << fact(val) << endl;
    }

    return 0;
}
