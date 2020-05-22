//练习 15.13：给定下面的类，解释每个 print 函数的机理：
// class base {
// public:
//     string name() {return basename;}
//     virtual void print(Ostream &os) {os << basename; }
// private:
//     string basename;
// };
// class derived : public base {
// public:
//     void print(ostream &os) { print(os); os << " " << i; }
// private:
//     int i;
// };

/*
* 基类 base 中的 print 函数打印自己的数据成员，没有问题。
* 派生类 derived 中的 print 调用 print 实际上调用的是自身，导致递归调用，这是错误的，应该改为 base::print(os)
*/
