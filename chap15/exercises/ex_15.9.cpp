//练习 15.9：在什么情况下，表达式的静态类型可能和动态类型不同？请给出三个静态类型与动态类型不同的例子。

/*
* 基类的指针或引用的静态类型可能与其动态类型不同。例如：
*（1）声明一个基类的指针变量指向它的派生类的对象。
*（2）声明一个基类的引用变量并绑定到它的派生类的对象上。
*（3）函数形参为基类引用，实参为派生类的时候，调用时，形参的静态类型与其动态类型不同。
*/
