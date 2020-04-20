//练习 12.12：p 和 sp  的定义如下，对于接下来的对 process 的每个调用，如果合法，解释它做了什么，如果不合法，解释错误的原因。
// auto p = new int();
// auto sp = make_shared<int>();
// (a) process(sp);
// (b) process(new int());
// (c) process(p);
// (d) process(shared_pre<int>(p));

/*
* (a) 合法，将 sp 作为参数传递给 process。
* (b) 不合法，new int() 返回的是一个 int *，process 需要的参数是 shared_pre<int>
* (c) 不合法，p 是一个普通指针。
* (d) 合法，利用 p 生成一个临时的 shared_ptr 传递给 process。
*/

