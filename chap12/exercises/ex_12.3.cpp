//练习 12.3：StrBlob 需要 const 版本的 push_back 和 pop_back 吗？如果需要，添加进去。否则，解释为什么不需要。

/*
* 不需要。const 版本的成员函数修饰的是 *this 对象。再当前情况下， this 指向的数据成员是 data，也是一个指针，
* const 只能限制 data 无法指向其它的对象但是不能限制 data 所指的 vector 添加或者删除元素，同时 push_back 和 pop_back 本身并不会改变 data 指针的指向。
* 所以这里 const 版本没有意义。
*/
