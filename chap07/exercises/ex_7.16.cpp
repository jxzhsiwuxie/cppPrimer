//练习 7.16：在类的定义中对访问说明符出现的位置和次数有限制么？如果有，是什么？
//什么样的成员应该定义在 public 说明符之后？什么样的成员应该定义在 private 说明符之后？

/*
* 类的定义中对于访问说明符出现的位置和次数并没有限制。
* 那些希望被类的用户访问的成员（一般是类的接口）应该放在 public 访问说明符之后；
* 那些不希望被类的使用者访问到的成员（一般是数据成员和辅助接口实现的成员函数）应该放在 private 访问说明符之后。
*/
