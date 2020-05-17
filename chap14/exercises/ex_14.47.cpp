//练习 14.47：说明下面这两个类型转换运算符的区别。
// struct Integral{
//     operator const int();
//     operator int() const;
// };

/*
* operator const int() 返回的是一个常量，但是函数本身可能会对 Integral 对象的数据造成修改。
* operator int() const 返回的是一个非常量，但是函数本身不会对 Integral 对象本身造成修改。
*/


