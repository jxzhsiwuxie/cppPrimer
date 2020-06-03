//练习 16.44：使用与第一题中相同的三个调用，如果 g 的函数参数声明为 T（而不是 T&&），确定 T 的类型。
//如果 g 的函数参数是 const T& 呢？

// template<typename T> void g(T&& val);
// int i = 0; const int ci = i;
// (a) g(i);    (b) g(ci);  (c) g(i * ci);

/*
* 如果 g 的函数参数是 T：
* (a) T 为 int，val 为 int
* (b) T 为 const int，val 为 const int
* (c) T 为 int &&，val 为 int&&
*/

/*
* 如果 g 的函数参数是 const T&：
* (a) T 为 int，val 为 const int&
* (b) T 为 int，val 为 const int&
* (c) T 为 int&，val 为 const int&
*/
