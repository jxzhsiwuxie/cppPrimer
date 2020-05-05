//练习 13.58：如果 sorted 定义如下，会发生什么：
// Foo Foo::sorted() const & {
//     return Foo(*this).sorted();   
// }

/*
* this 是一个 const 的左值引用，Foo(*this) 返回的还是一个右值值，接着便会调用 Foo Foo::sorted() && 版本的函数，然后返回正确的值。
*/
