//练习 7.58：下面的静态数据成员的声明和定义有错误么？请解释原因。
// example.h
// class Example {
// public:
//     static double rate = 6.5;
//     static const int vecSize = 20;
//     static vector<double> vec(vecSize);
// };
// example.C
// # include "example.h"
// double Example::rate;
// vector<double> Example::vec;

/*
* rate 的声明有问题。带有类内初始值的静态成员必须提供常量值。
* vec 的声明有问题，类内初始值并不是初始化而是在初始化之后赋予一个值，所以是赋值操作，
* 而 vec 的声明语句使用了直接初始化语句。
*/

