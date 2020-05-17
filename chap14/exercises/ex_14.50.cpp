//练习 14.50：在初始化 ex1 和 ex2 的过程中，可能用到哪些类类型转换序列呢？说明初始化是否正确并解释原因。
// struct LongDouble {
//     LongDouble(double = 0.0);
//     operator double();
//     operator float();
// };
// LongDouble ldObj;
// int ex1 = ldObj;
// int ex2 = ldObj;

/*
* LongDouble ldObj; 初始化过程中使用默认构造函数。
* int ex1 = ldObj; 初始化具有二义性。
* int ex2 = ldObj; 初始化具有二义性。
*/

