//练习 16.26：假设 NoDefault 是一个没有默认构造函数的类，我们可以显式实例化 vector<BoDefault> 吗？如果不可以，解释为什么。

/*
* 在一个类模板的实例化定义中，所有类型必须能用于模板的所有成员。
* 显式实例化 vector<NoDefault> 将会实例化模板 vector 的所有成员，包含默认构造函数，但是类型 NoDefault 没有默认构造函数，
* 所以不能显式实例化 vector<NoDefault>。
*/
