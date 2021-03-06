//练习 13.1：拷贝构造函数是什么？什么时候使用它？

/*
* 如果一个构造函数的第一个参数是自身类类型的引用，并且任何额外的参数都有默认值，则此构造函数是拷贝构造函数。
* 使用拷贝构造函数的场合：
*（1）使用 = 运算符来初始化一个类类型的变量。
*（2）将一个对象作为实参传递给一个非引用类型的形参。
*（3）从一个返回类型为非引用类型的函数返回一个对象。
*（4）用花括号列表初始化一个数组中的元素或一个聚合类中的成员。
*（5）初始化标准库容器或者调用其 insert 或 push_back 成员时，容器会对其元素进行拷贝初始化。
*/
