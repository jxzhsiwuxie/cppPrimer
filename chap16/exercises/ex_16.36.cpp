//练习 16.36：进行下面的调用会发生什么？
// template <typename T> f1(T, T);
// template <typename T1, typename T2> f2(T1, T2);
// int i = 0, j = 42, *p1 = &i, *p2 = &j;
// const int *cp1 = &i, *cp2 = &j;
// (a) f1(p1, p2);      (b) f2(p1, p2);     (c) f1(cp1, cp2);
// (d) f2(cp1, cp2);   (e) f1(p1, cp1);    (f) f2(p1, cp1);

/*
* (a) T 为 int*
* (b) T1 为 int*，T2 为 int*
* (c) T 为 const int*
* (d) T1 为 const int*，T2 为 const int*
* (e) T 为 const int*
* (f) T1 为 int*，T2 为 const int*
*/
