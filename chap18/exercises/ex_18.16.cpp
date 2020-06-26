//练习 18.16：假定在下面代码中标记为 “位置 1” 的地方是对命名空间 Exercise 中所有成员的 using 声明，请解释代码的含义。
//如果这些 using 声明出现在 “位置 2” 又会怎样？将 using 声明变为 using 指示，重新回答之前的问题。
// namespace Exercise {
//     int ivar = 0;
//     double dvar = 0;
//     const int limit = 1000;
// }
// int ivar = 0;
// 位置 1
// void manip() {
//     //位置 2
//     double dvar = 3.1416;
//     int iobj = limit + 1;
//     ++ivar;
//     ++::ivar;
// }

/*
* using 声明出现在 “位置 1”，using Exercise::ivar; 在编译时会报错，因为 ivar 已经定义过了。
* using 声明出现在 “位置 2”，double dvar = 3.14; 在编译时会报错。
*/

/*
* using 指示出现在 “位置 1”，++ivar 会报错，无法确定使用的是哪一个 ivar
* using 指示出现在 “位置 2”，++ivar 会报错，无法确定使用的是哪一个 ivar
*/


