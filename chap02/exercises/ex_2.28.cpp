//练习 2.28：说明下面这些定义是什么意思，挑出其中不合法的。
/*
* (a) int i, *const cp;             (b) int *p1, *const p2;
* (c) const int ic, &r = ic;        (d) const int *const p3;
* (e) const int *p;
*/

/*
* (a) 定义 int 型变量 i，这是合法的；定义指向 int 类型对象的 const 指针，这里是不合法的，因为必须要初始化 cp。
* (b) 定义 int 型指针 p1 是合法的；定义 int 型的 const 指针 p2 是不合法的，因为没有初始化 p2。
* (c) 定义 int 型常量 ic 是不合法的，因为没有初始化；定义 const int 对象的引用 r 并使用 ic 来初始化是合法的。
* (d) 定义指向 const int 型对象的 const 指针必须要初始化，所以这个是不合法的。
* (e) 定义指向常量整型对象的指针 p，合法的。
*/