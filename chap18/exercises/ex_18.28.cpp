//练习 18.28：已知存在如下的继承体系，在 VMI 类的内部那些继承而来的成员无需前缀限定符就能直接访问？哪些必须有限定符才能访问？说明你的原因。
// struct Base {
//     void bar(int);       //默认情况下是公有的
// protected:
//     int ival;
// };
// struct Derived1: virtual public Base {
//    void bar(char);        //默认情况下是公有的
//    void foo(char);
// protected:
//    char cval;
// };
// struct Derived2: virtual public Base{
//     void foo(int);        //默认情况下是公有的
// protected:
//     int ival;
//     char cval;
// };
// class VMI: public Derived1, public Derived2 { };

/*
* cval 具有二义性，必须要限定符才能访问，ival 可以直接访问，
* bar(char) 可以直接访问，bar(int) 需要限定符才能访问，
* foo(char) 和 foo(int) 都需要限定符才能访问。
*/
