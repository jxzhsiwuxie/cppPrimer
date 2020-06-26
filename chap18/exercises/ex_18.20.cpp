//练习 18.20：在下面的代码中，确定哪个函数与 compute 调用匹配。列出所有候选函数和可行函数，
//对于每个可行函数的实参与形参的匹配过程来说，发生了哪种类型转换？
// namespace primerLib {
//     void compute();
//     void compute(const void *);
// }
// using primerLib::compute;
// void compute(int);
// void compute(double, couble = 3.4);
// void compute(char *, char * = 0);
// void f() {
//     compute(0);
// }
//如果将 using 声明置于 f 函数中 compute 函数的调用点之前将发生什么情况？重新回答那些问题。

/*
* 与调用匹配最好的是 void compute(int);
* 候选函数：
* void compute();
* void compute(const void *);
* void compute(int);
* void compute(double, couble = 3.4);
* void compute(char *, char * = 0);
* 可行函数：
* void compute(const void *);
* void compute(int);
* void compute(double, couble = 3.4);
* void compute(char *, char * = 0);
*/

/*
* 如果将 using 声明置于 f 函数中 compute 函数的调用点之前则屏蔽了 f 外部声明的 compute 函数，最终匹配到 void compute(const void *);
*/
