//练习 13.15：假定 numbered 定义了一个拷贝构造函数，能生成一个新的序列号。这会改变上一题中调用的输出结果么？
//如果会改变，为什么？新的输出结果是什么？

/*
* 会改变。
* 函数 f 的参数是 numbered 的非引用类型，在调用时，实参通过拷贝构造函数初始化形参。
* 新的输出结果是三个不同的内容。
*/
