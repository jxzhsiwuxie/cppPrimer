//练习 7.35：解释下面代码的含义，说明其中的 Type 和 initVal 分别使用了哪个定义。
//如果代码存在错误，亲尝试修改它。
// typedef string Type;
// Type initVal();
// class Exercise {
// public:
//     typedef double Type;
//     Type setVal(Type);
//     Type initVal();
// private:
//     int val;
// };
// Type Exercise::setVal(Type parm) {
//     val = parm + initVal();
//     return val;
// }

/*
*（1） 首先类内部定义类型 Type 属于重复定义，与类外部定义的 Type 只能留一个。
* 如果选择留下类外定义的 Type 那么接下来所有使用到的 Type 都是 stirng 的别名，
* 但此时全局函数的声明就有问题了，因为此时 Type 还未定义，同时此时 setVal 定义用到的 val 又是 int，无法与 Type 做相加操作；
* 如果选择留下类内定义的 Type 则成员函数 setVal 的定义就需要修改，其返回值应为 Exercise::Type，
* 这样所有用到的 Type 就都是 double 的别名。
*（2）至于成员函数 setVal 的定义中使用到的 initVal 则是类的成员函数而不是全局函数 initVal。
* 所以无论哪种方案都需要修改原本代码的意图。这里选择保留类外部定义的 Type。
*/

// typedef string Type;
// Type initVal();
// class Exercise {
//    public:
//     Type setVal(Type);
//     Type initVal();

//    private:
//     int val;
// };
// Type Exercise::setVal(Type parm) {
//     Type val = parm + initVal();
//     return val;
// }

