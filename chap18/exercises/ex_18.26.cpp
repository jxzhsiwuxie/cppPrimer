//练习 18.26：

#include <string>
#include <vector>

struct Base1 {
    void print(int) const;  //默认情况下是共有的
   protected:
    int ival;
    double dval;
    char cval;

   private:
    int *id;
};

struct Base2 {
    void print(double) const;  //默认情况下是共有的
   protected:
    double fval;

   private:
    double dval;
};

struct Derived : public Base1 {
    void print(std::string) const;  //默认情况下是共有的
   protected:
    std::string sval;
    double dval;
};

struct MI : public Derived, public Base2 {
    void print(std::vector<double>);  //默认情况下是共有的

   protected:
    int *ival;
    std::vector<double> dvec;
};

//已知如上所示的继承体系，下面对 print 的调用为什么是错误的？适当修改 MI，令其对 print 的调用可以编译通过并正确执行。
// MI mi;
// mi.print(42);

/*
* MI 重新定义了 print 函数，mi.print 将会直接调用这个重新定义的版本，但是参数不符合，导致错误。
* 可以在 MI 使用 using 声明来引入基类的 print 函数
* using Base1::print;
* using Base2::print;
* using Derived::print;
*/

