//练习 18.29：已知有如下的类继承关系：
// class Class { ... };
// class Base: public Class { ... };
// class D1: virtual public Base { ... };
// class D2: virtual public Base { ... };
// class MI: public D1, public D2 { ... };
// class Final: public MI, public Class { ... };
// (a) 当作用于一个 Final 对象时，构造函数和析构函数的执行次序依次是什么？
// (b) 在一个 Final 对象中有几个 Base 部分？几个 Class 部分？
// (c) 下面的哪些赋值运算将造成编译错误？
// Base *pb;    Class *pc;      MI *pmi;    D2 *pd2;
// (a) pb = new Class;      (b) pc = new Final;
// (c) pmi = pb;            (d) pd2 = pmi;


/*
* (a) 构造函数顺序：Class 构造函数、Base 构造函数、D1 构造函数、D2 构造函数、Class构造函数
* (b) 在一个 Final 对象中，有一个 Base 部分，两个 Class 部分
* (c) 赋值运算 (a)、(c) 将会造成编译错误。
*/
