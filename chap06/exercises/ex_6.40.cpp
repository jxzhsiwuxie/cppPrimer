//练习 6.40：下面那个声明是错误的？为什么？
// (a) int ff(int a, int b = 0, int c = 0);
// (b) char *init(int ht = 24, int wd, char backgrnd);

/*
* 声明 (b) 是错误的。
* 如果一个形参被赋予了默认值，则其后面所有的形参都必须被赋予默认值。否则这个函数声明就是错误的。
*/
