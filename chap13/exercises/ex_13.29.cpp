//练习 13.29：解释 swap(HasPtr &, HasPtr &) 中对 swap 的调用不会导致递归循环。

/*
* swap(HasPtr &, HasPtr &) 的参数类型是 HasPtr&，而内部使用的是 std::swap，其参数是内置类型，调用的不是同一个函数，也就不会形成递归。
*/
