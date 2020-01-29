//练习 2.3：读程序写结果。

#include <iostream>

int main()
{
    unsigned u = 10, u2 = 42;

    std::cout << u2 - u << std::endl; //32
    std::cout << u - u2 << std::endl; //-32 + 4294967296 ==> 4294967264

    int i = 10, i2 = 42;
    std::cout << i2 - i << std::endl; //32
    std::cout << i - i2 << std::endl; //-32
    std::cout << u - i << std::endl;  //0

    return 0;
}