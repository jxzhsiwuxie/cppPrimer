//练习 16.49：解释下面每个调用会发生什么？
// template <typename T> void f(T);
// template <typename T> void f(const T*);
// template <typename T> void g(T);
// template <typename T> void g(T*);
// int i = 42, *p = &i;
// const int ci = 0, *p2 = &ci;
// g(42);   g(p);   g(ci);  g(p2);
// f(42);   f(p);   f(ci);  f(p2);

/*
* g(42) 将调用 template <typename T> void g(T);
* g(p) 将调用 template <typename T> void g(T*);
* g(ci) 将调用 template <typename T> void g(T);
* g(p2) 将调用 template <typename T> void g(T*);
*/

/*
* f(42) 将调用 template <typename T> void f(T);
* f(p) 将调用 template <typename T> void f(T);
* f(ci) 将调用 template <typename T> void f(T);
* f(p2) 将调用 template <typename T> void f(const T*);
*/
