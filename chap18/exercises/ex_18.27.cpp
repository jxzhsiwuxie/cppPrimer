//练习 18.27：已知如上所示的继承体系，同时假定为 MI 添加了一个名为 foo 的函数：
// int ival;
// double dval;
// void MI::foo(double cval){
//     int dval;
//     //练习中的问题发生在此处
// }
// (a) 列出在 MI::foo 中可见的所有名字。
// (b) 是否存在某个可见的名字是继承自多个基类的？
// (c) 将 Base1 的 dval 成员与 Derived 的 dval 成员求和后赋给 dval 的局部实例。
// (d) 将 MI::devc 的最后一个元素的值赋给 Base2::fval。
// (e) 将从 Base1 继承的 cval 赋值给从 Derived 继承的 sval 的第一个字符。

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
    void foo(double);

   protected:
    int *ival;
    std::vector<double> dvec;
};

int ival;
double dval;
void MI::foo(double cval) {
    int dval;
    /*
    * (a) dval 只有当前定义的 int dval；ival 只有 MI 中定义的 int *ival；MI 中的 dvec；
    * Base1 中的 cval 和 id；Base2 中的 fval；Derived 中的 sval 以及所有的 print
    */
    /*
    * (b) print 继承自多个基类
    */
    /*
    * (c) dval = Base1::dval + Derived::dval;
    */
    /*
    * (d) Base2::fval = dvec.back();
    */
    /*
    * (e) sval[0] = cval;
    */
   
}