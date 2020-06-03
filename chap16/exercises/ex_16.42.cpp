//练习 16.42：对下面每个调用，确定 T 和 val 类型：
// template<typename T> void g(T&& val);
// int i = 0; const int ci = i;
// (a) g(i);    (b) g(ci);  (c) g(i * ci);


/*
* (a) T 类型为 int&， val 类型为 int&
* (b) T 类型为 const int&，val 类型为 const int&
* (c) T 类型为 int，val 类型为 int&&
*/
