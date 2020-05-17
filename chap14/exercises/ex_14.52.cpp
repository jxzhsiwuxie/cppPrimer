//练习 14.52：在下面地加法表达式中分别使用了哪个 operator+？列出候选函数、可行函数以及每个可行函数的实参执行的类型转换：
// struct LongDouble{
//     //用于演示的成员 operator+，通常情况下 + 是个非成员
//     LongDouble operator+(const SmallInt&);
//     //其它成员与 14.9.2 节（第 521 页）一致
// };
// LongDouble operator+(LongDouble&, double);
// SmallInt si;
// LongDouble ld;
// ld = si + ld;
// ld = ld + si;

/*
* 对于 ld = si + ld;
* 候选函数：
* LongDouble operator+(const SmallInt&);
* LongDouble operator+(LongDouble&, double);
* 可行函数：
* 没有
*/

/*
* 对于 ld = ld + si;
* 候选函数：
* LongDouble operator+(const SmallInt&);
* LongDouble operator+(LongDouble&, double);
* 可行函数：
* LongDouble operator+(const SmallInt&);
* LongDouble operator+(LongDouble&, double);
* 对于第一个，精确匹配；对于第二个，si 先转换为 int，然后 int 再转换为 double。
*/