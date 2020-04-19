//练习 12.9：解释下面代码执行的结果。
// int *q = new int(42), *r = new int(100);
// r = q;
// auto q2 = make_shared<int>(42), r2 = make_shared<int>(100);
// r2 == q2;

/*
* 代码执行完毕之后，r 最初指向的内存将不能被释放同时也不能被访问。
* q2 最初指向的内存被正确释放。
*/

