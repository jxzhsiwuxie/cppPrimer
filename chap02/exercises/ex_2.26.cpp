//练习 2.26：下面哪些句子是合法的？如果有不合法的句子，请说明为什么？
/*
* (a) const int buf;        (b) int cnt = 0;
* (c) const int sz = cnt;   (d) ++cnt; ++sz;
*/

/*
* (b) 和 (c) 是合法的。
* (a) 定义 const 变量必须初始化。
* (d) ++sz; 是不合法的，因为不能修改 const 变量的值。
*/