//练习 18.23：使用练习 18.22 的继承体系以及下面定义的类 D，同时假定每个类都定义了默认构造函数，请问下面的哪些类型转换是不被允许的？
// class D: public X, public C { ... };
// D *pd = new D;
// (a) X *px = pd;      (b) A *pa = pd;
// (c) B *pb = pd;      (d) C *pc = pd;

/*
* 都是允许的。
*/

class A {};
class B : public A {};
class C : public B {};
class X {};
class Y {};
class Z : public X, public Y {};
class D : public X, public C {};

int main() {
    D *pd = new D;
    X *px = pd;
    A *pa = pd;
    B *pb = pd;
    C *pc = pd;
    return 0;
}