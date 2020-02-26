//练习 6.37：为上一题的函数再写三个声明，一个使用类型别名，另一个使用尾置返回类型，最后一个使用 decltype 关键字。
//你觉得哪种形式最好？为什么？


/*
* 练习 6.3.36 中版本
*/
// string (&refString())[10] { /*...*/ }

/*
* 使用类型别名的版本
*/
// using strArr = string[10];
// strArr &refString() { /*...*/ }

/*
* 使用尾置返回类型的版本
*/
// auto refString() -> string (&)[10] { /*...*/ }

/*
* 使用 decltype 关键字的版本
*/
// string tmp[10];
// decltype(tmp) &refString() { /*...*/ }

/*
* 使用尾置返回类型的形式最好。
* 一方面返回值的类型最直观，另一方面代码也最简洁。
*/