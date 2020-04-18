//练习 12.2：编写你自己的 StrBlob 类，包含 const 版本的 front 和 back。

#include "StrBlob.h"
#include <iostream>

int main() {
    StrBlob b1({"aa", "bb", "cc"});
    const StrBlob b2({"aa", "bb", "cc"});

    b1.push_back("dd");
    b1.pop_back();

    //不能添加
    //b2.push_back("dd");

    b1.front() = "ff";

    //不能给 front 返回的元素赋值
    //b2.front() = "ff";



    std::cout << b1.front() << std::endl;
    std::cout << b2.front() << std::endl;

    std::cout << b1.back() << std::endl;
    std::cout << b2.back() << std::endl;

    return 0;
}
