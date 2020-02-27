//练习 6.50：已知有第 217 页对函数 f 的声明，对于下面的每个调用列出可行函数。其中哪个函数是最佳匹配？
//如果调用不合法，是因为没有可匹配的函数还是因为调用具有二义性？
// (a) f(2.56, 42);     (b) f(42);      (c) f(42, 0);       (d) f(2.56, 3.14);

/*
* 函数 f 的声明：
*/
// void f();
// void f(int);
// void f(int, int);
// void f(double, double = 3.14);

/*
* (a) 可行函数：
* void f(int, int);         void f(double, double = 3.14);
* 最佳匹配函数：没有。
* 调用不合法，因为调用具有二义性。
*/

/*
* (b) 可行函数：
* void f(int);          void f(double, double = 3.14);
* 最佳匹配函数：
* void f(int);
*/

/*
* (c) 可行函数：
* void f(int, int);         void f(double, double = 3.14);
* 最佳匹配函数：
* void f(int, int);
*/


/*
* (d) 可行函数：
* void f(int, int);         void f(double, double = 3.14);
* 最佳匹配函数：
* void f(double, double = 3.14);
*/
