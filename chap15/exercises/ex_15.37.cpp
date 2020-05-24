//练习 15.37：如果在派生类中含有 shared_ptr<Query_base> 而非 Query类型的成员，则你的类需要做出怎样的改变？

/*
* 在派生类的构造函数中利用 Query 的拷贝构造函数新建一个指向 Query 的 shared_ptr，用来初始化这个成员。
* 同时在调用 repo 和 eval 函数时改用指针的方式。
*/
