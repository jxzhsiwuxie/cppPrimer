//练习 18.1：在下列 throw 语句中异常对象的类型是什么？
// (a) range_error r("error");          (b) exception *p = &r;
//     throw r;                             throw *p
//如果将 (b) 中的 throw 语句写成 throw p 将发生什么情况？

/*
* (a) range_error
* (b) exception
* 如果将 throw 语句写成 throw p，则泡泡出异常后 r 的析构函数被调用，在 catch 语句中不能再访问异常对象。
*/
