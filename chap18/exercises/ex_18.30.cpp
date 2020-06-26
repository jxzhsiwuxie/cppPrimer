//练习 18.30：在 Base 中定义一个默认构造函数、一个拷贝构造函数和一个接受 int 形参的构造函数。在每个派生类中分别定义这三种构造函数，
//每个构造函数应该使用它的实参初始化其 Base 部分。

class Class {};

class Base : public Class {
   public:
    Base() = default;
    Base(const Base &base) {}
    Base(int i) {}
};

class D1 : virtual public Base {
   public:
    D1() {}
    D1(const D1 &d1) : Base(d1) {}
    D1(int i) : Base(i) {}
};

class D2 : virtual public Base {
   public:
    D2() {}
    D2(const D2 &d2) : Base(d2) {}
    D2(int i) : Base(i) {}
};

class MI : public D1, public D2 {
   public:
    MI() {}
    MI(const MI &mi) : Base(mi), D1(mi), D2(mi) {}
    MI(int i) : Base(i), D1(i), D2(i) {}
};

class Final : public MI, public Class {
   public:
    Final() {}
    Final(const Final &f) : Base(f), MI(f) {}
    Final(int i) : Base(i), MI(i) {}
};