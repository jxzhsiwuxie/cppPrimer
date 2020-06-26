//练习 18.25：假设我们有两个基类 Base1 和 Base2，它们各自定义了一个名为 print 的虚成员和一个虚析构函数。
//从这两个基类中我们派生出下面的类，它们都重新定义了 print 函数：
// class D1: public Base1 { /* .. */ };
// class D2: public Base2 { /* .. */ };
// class MI: public D1, public D2 { /* .. */ };
//通过下面的指针，指出在每个调用中分别使用了哪个函数：
// Base1 *pb1 = new MI;
// Base2 *pb2 = new MI;
// D1 *pd1 = new MI;
// D2 *pd2 = new MI;
// (a) pb1->print();    (b) pd1->print();   (c) pd2->print();
// (d) delete pb2;      (e) delete pd1;     (f) delete pd2;

/*
* (a)、(b)、(c) 都调用的 MI 中定义的 print 函数。
* (d)、(e)、(f) 都先调用 MI 的析构函数，然后依次调用其基类的析构函数。
*/

