//练习 2.30：对于下面这些语句，请说明对象被声明成了顶层 const 还是底层 const？
/*
* const int v2 = 0; //顶层 const。
* int v1 = v2;  //非 const 变量。
* int *p1 = &v1, &r1 = v1;  //p1 和 r1 都既无顶层 const 也无底层 const。
* const int *p2 = &v2, *const p3 = &i, &r2 = v2;
* p2 是底层 const，p3 既是顶层 const 也是底层 const，r2 是底层 const。
*/