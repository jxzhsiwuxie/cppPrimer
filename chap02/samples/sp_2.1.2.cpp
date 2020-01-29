//当一个算数表达式中既有无符号数又有 int 值时，那个 int 值就会转换成无符号数。
//unsigned int 取之范围 0～4294967296
//把负数转换成无符号数等于这个负数加上无符号数的模。

#include <iostream>

int main()
{
    unsigned u = 10;
    int i = -42;

    std::cout << i + i << std::endl; //-84
    //10 + （-42 + 4294967296）
    std::cout << u + i << std::endl; //4294967264


    return 0;
}