//练习 2.10：下列变量的初始值分别是什么？

#include <iostream>
#include <string>

std::string global_str;
int global_int;

int main()
{
    int local_int;
    std::string local_str;

    return 0;
}

/*
* 变量 global_str 和 global_int 定义在所有函数的外部，所以即使在定义的时候没有指定初始值也会被默认初始化。
* global_str 是一个类类型的变量，将会被默认初始化为一个空字符串，
* global_int 是一个内置类型（int）的变量，将会被初始化为0。
*
* local_int 和 local_str都是定义在函数内部的变量。
* 由于 local_int 又是内置类型的变量，所以不会被默认初始化，其值是未知的，不确定的。
* 由于 local_str 是类类型的变量，所以即使它是在函数内定义的，它的初始化行为又 std::string 本身决定，
* local_str 将被默认初始化为一个空字符串。
*/