//练习 2.32：下面的代码是否合法？如果非法，请设法将其修改正确。
// int null = 0, *p = null;

/*
* int null = 0 是合法的，但是 int *p = null 是不合法的。
* p 是一个指针变量，不能用 int 型的变量来初始化它。
* 可以修改为：
* int null = 0, *p = 0;
*/