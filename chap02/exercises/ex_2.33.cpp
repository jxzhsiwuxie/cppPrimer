//练习 2.33：利用本节定义的变量，判断下列语句的运行结果。
/*
* a = 42; b = 42; c = 42;
* d = 42; e = 42; g = 42;
*/

/*
* 本节定义的变量：
* int i = 0, &r = i;
* auto a = r;
* const int ci = i, &cr = ci;
* auto b = ci;
* auto c = cr;
* auto d = &i;
* auto e = &ci;
* const auto f = ci;
* auto &g = ci;
*/

/*
* 正确。a 是一个 int 型变量，所以  a= 42; 只是单纯的给 a 赋一个新的值。
* 正确。ci 是一个 const int 型的变量，auto b = ci; 会忽略掉顶层的 const，所以 b 的类型是 int。b = 42; 只是给 b 赋一个新的值。
* 正确。cr 只是 ci 的别名，所以同样 c 的类型是 int。c = 42; 只是给 c 赋一个新的值。
* 错误。i 是 int 类型的变量，所以 d 是一个指向整型变量的指针，因此 d = 42; 右边的整数与 d 类型不匹配，编译器会报错。
* 错误。ci 类型为 const int，所以 e 是一个指向整型常量的指针，将一个整数赋给一个指针编译器报错。
* 错误。ci 类型为 const int，所以 g 是一个整型常量的引用， g = 42; 等价于给常量 ci 重新赋值，所以错误。
*/