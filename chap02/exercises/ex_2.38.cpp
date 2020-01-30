//练习 2.38：说明由 decltype 指定类型和由 auto 指定类型有何区别。
//请举一个例子，decltype 指定的类型与 auto 指定的类型一样；再举一个例子，
//decltype 指定的类型和 auto 指定的类型不一样。

/*
*（1）通过decltype 指定类型时并不需要计算表达式而通过 auto 指定类型需要计算表达式。
*（2）处理顶层 const 时，如果 decltype 使用的是一个变量，则 decltype 返回的类型包括顶层 const，而 auto 返回的类型不包括。
*（3）处理引用时，如果 decltype 使用的是一个变量，则 decltype 返回的是引用类型，而 auto 返回的是基本数据类型。
*/

/*
* int a = 1, &b = a;
* auto autoC = a; decltype(a) decltC = a;  //autoC 和 decltC 类型都是 int。
* auto autoD = b; decltype(b) decltD = a;  //autoD 是 int 型变量，但是 decltD 是 int& 类型的变量。
*/