//练习 19.3：一直存在如下的类继承体系，其中每个类分别定义了一个共有的默认构造函数和一个虚析构函数：
// class A { /* ... */ };
// class B: public A { /* ... */ };
// class C: public B { /* ... */ };
// class D: public B, public A { /* ... */ };
//下面的哪个 dynamic_cast 将失败？
// (a) A * pa = new C;
//     B *pb = dynamic_cast<B *>(pa);
// (b) B *pb = new B;
//     C *pc = dynamic_cast<C *>(pb);
// (c) A *pa = new D;
//     B *pb = dynamic_cast<B *>(pa);


/*
* (b) 将会失败
*/
