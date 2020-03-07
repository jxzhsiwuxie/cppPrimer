//练习 7.51：vector 将其单参数的构造函数定义成 explicit 的，而 string 则不是，你觉得原因何在？

/*
* string 的单参数构造函数的形参类型为 const char*，这个很明确表明参数是一个字符串，所以使用起来不会产生意料之外的错误。
* vector 的单参数构造函数的形参类型是不确定的，例如对于 vector<int> 类型的 vecotr，则其单参数构造函数的新参是一个 int，
* 如果不定义成 explict，则 vector<int> ivec = 2; 这种定义会让人误解.
*/
