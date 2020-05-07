//练习 14.14：你觉得为什么调用 operator+= 来定义 operator+ 比其它方法更有效？

/*
* operator+= 返回的是对象的引用，operator+ 返回的是对象的副本，调用 operator+= 可以减少依次对象的拷贝。
*/
