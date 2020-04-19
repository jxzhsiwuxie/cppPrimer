//练习 12.8：下面的函数是否有错误？如果有，情节是原因。
// bool b() {
//     int *p = new int;
//     // ...
//     return p;
// }

/*
* 函数本身语法没有错误，但是逻辑有错误。
* 按照正常逻辑，在使用 p 之后应该释放 p 并同时将 p 指向 nullptr，但是这样一来，函数的返回值就恒为假了。
* 另一方面如果不将 p 指向 nullptr，则函数的返回值恒真，并且返回值存在访问已释放的内存数据的危险。
*/

#include <iostream>

bool b() {
    int *p = new int;
    // ...
    delete p;
    p = nullptr;
    return p;
}

int main() {
    if (b())
        std::cout << "指针不为空" << std::endl;
    else
        std::cout << "指针为空" << std::endl;
    return 0;
}
