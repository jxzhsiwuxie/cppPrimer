//练习 16.35：下面调用中，哪些是错误的（如果有的话）？如果合法，T 的类型是什么？如果不合法，问题何在？
// template <typename T> T calc(T, int);
// template <typename T> T fcn(T, T);
// double d; float f; char c;
// (a) calc(c, 'c');    (b) calc(d, f);
// (c) fcn(c, 'c');     (d) fcn(d, f);

/*
* (a) 合法，T 的类型为 char
* (b) 合法，T 的类型为 double
* (c) 合法，T 的类型为 char
* (d) 不合法，fcn 两个形参都是模板参数，d 和 f 的类型不相同
*/
