//练习 13.52：详细解释第 478 页中 HasPtr 对象的赋值发生了什么？特别是，一步一步描述 hp、hp2 以及 HasPtr 的
//赋值运算符中的参数 rhs 的值发生了什么变化。

/*
* hp = hp2;
* 调用的是拷贝赋值运算符，HasPtr &operator=(const HasPtr &rhs) 中的形参 rhs 绑定到 hp2 上，然后将 hp2 的数据逐元素拷贝到 this（hp） 上，然后返回一个左值 *this。
* 在此过程中 rhs 没有变化。
*/

/*
* hp = std::move(hp2);
* 利用 std::move 得到 hp2 对应的右值，移动赋值运算符的形参 rhs 绑定到这个右值上，然后将 hp2 上的数据直接赋值给 hp，将原本 hp 上的数据直接赋值给 hp2，然后返回 *this。
* 函数结束后将会调用 hp2 的析构函数，所以 hp 接管了原本 hp2 上的值，而 hp2 的值将变更的未知。
*/
