//练习 14.21：编写 Sales_data 类的 + 和 += 运算符，使得 + 执行实际的加法操作而 += 调用 +。相比于 14.3 节（第 497 页）和 14.4 节（第 500 页）对这两个运算符的定义，
//本题的定义有何缺点？试讨论之。

/*
* 本题的定义多调用了一次赋值操作并且创建了一个局部变量，这些都是不必要的。
*/
