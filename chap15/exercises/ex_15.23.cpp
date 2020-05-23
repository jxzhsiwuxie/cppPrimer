//练习 15.23：假设第 550 页的 D1 类需要覆盖它继承而来的 fcn 函数，你应该如何对其进行修改？如果你修改之后 fcn 匹配了 Base 中的定义，
//则该节的那些调用语句该如何解析？

class Base {
   public:
    virtual int fcn() { return 0; }
};

class D1 : public Base {
   public:
   //将这里参数改为与 Base 中 fcn 的参数列表一样即可
    int fcn() { return 1; }
    virtual void f2() {}
};

class D2 : public D1 {
   public:
    int fcn(int) { return 2; }
    int fcn() { return 3; }
    void f2() {}
};

int main() {
    Base bobj;
    D1 d1obj;
    D2 d2obj;

    Base *bp1 = &bobj, *bp2 = &d1obj, *bp3 = &d2obj;
    bp1->fcn();     //虚调用，在运行时调用 Base::fcn
    bp2->fcn();     //虚调用，在运行时调用 D1::fcn
    bp3->fcn();     //虚调用，在运行时调用 D2::fcn

    D1 *d1p = &d1obj;
    D2 *d2p = &d2obj;
    //bp2->f2();    //错误调用
    d1p->f2();      //虚调用，在运行时调用 D1::f2
    d2p->f2();      //虚调用，在运行时调用 D2::f2

    return 0;
}
