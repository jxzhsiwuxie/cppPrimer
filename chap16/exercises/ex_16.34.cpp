//练习 16.34：对下面的代码解释每个调用是否合法。如果合法，T 的类型是什么？如果不合法，为什么？
// template <class T> int compare(const T&, const T&);
// (a) compare("hi", "world");  (b) compare("bye", "dad");

/*
* (a) 不合法，字符串字面值本质是字符数组，对于引用类型的形参来说，数组不会转换为指针，所以长度不同的数组是不同的类型。
* (b) 合法。
*/

