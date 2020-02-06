//练习 4.34：根据本节给出的变量定义，说明下面的表达式中将发生什么样的类型转换：
// (a) if(fval)     (b) dval = fval + ival;     (c) dval + ival * cval;
//需要注意每种运算符遵循的是左结合律还是右结合律。

/*
* 本节的变量定义：
* bool flag;    char cval;     short sval;    unsigned short usval;   int ival;
* unsigned int uival;   long lval;    unsigned long ulval;    float fval;    double dval;
*/

/*
* (a) float 类型转换为 bool 类型，如果 flag 为 0 则为假否则为真。
* (b) 首先在计算右侧表达式的时候 int 类型转换为 float 类型，然后再赋值的时候 float 类型转换为 double 类型。
* (c) char 提升为 int 类型与 ival 做乘法，结果转换为 double 类型与 dval 做加法运算。
*/
