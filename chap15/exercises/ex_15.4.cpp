//练习 15.4：下面哪条声明语句是不正确的？请解释原因。
// class Base {...};
// (a) class Drived : public Drived {...};
// (b) class Drived : private Base {...};
// (c) class Drived : public Base;

/*
* (a) 不正确，类不能继承它自身。
* (c) 不正确，派生类的声明与普通的类声明一样，不能将基类包含在声明语句中。
*/
