//练习 1.7：编译一个包含不正确的嵌套注释的程序，观察编译器返回的信息。

#include <iostream>

/*
* 这里是注释。/* 这里有错误的嵌套注释*/
*/

int main(){
    std::cout << "Hello World." << std::endl;

    return 0;
}

//编译器错误信息：
// .\ex_1.7.cpp:7:2: error: expected unqualified-id before '/' token
//  */
//   ^