//如果 sorted 定义如下，会发生什么：
// Foo Foo::sorted() const & {
//     Foo ret(*this);
//     return ret.sorted();   
// }

/*
* 递归调用并且无限循环。
*/
