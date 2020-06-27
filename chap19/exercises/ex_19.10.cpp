//练习 19.10：已知存在如下的类继承体系，其中每个类定义了一个默认构造函数和虚析构函数。下面的语句将打印哪些类型名字。
// class A { /* ... */ };
// class B : public A { /* ... */ };
// class C : public B { /* ... */ };
// (a) A *pa = new C;
//     cout << typeid(pa).name() << endl;
// (b) C cobj;
//     A &ra = cobj;
//     cout << typeid(&ra).name() << endl;
// (c) B *px = new B;
//     A &ra = *px;
//     cout << typeid(ra) << endl;


/*
* (a) 打印指针类型
* (b) 打印指针类型
* (c) 打印 B 的类型
*/


#include <iostream>

using std::cout;
using std::endl;

class A {
   public:
    virtual ~A() {}
};

class B : public A {
   public:
    virtual ~B() {}
};

class C : public B {
   public:
    virtual ~C() {}
};

int main() {
    A *pa = new C;
    cout << typeid(pa).name() << endl;

    C cobj;
    A &ra = cobj;
    cout << typeid(&ra).name() << endl;

    // B *px = new B;
    // A &ra = *px;
    // cout << typeid(ra) << endl;

    return 0;
}
