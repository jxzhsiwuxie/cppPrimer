//练习 4.35：假设有如下的定义：
// char cval;   int ival;   unsigned int ui;
// float fval;  double dval;
//请回答下面的表达式中发生了隐式类型转换么？如果有，指出来。
// (a) cval = 'a' + 3;       (b) fval = ui - ival * 1.0;
// (c) dval = ui * fval;     (d) cval = ival + fval + dval;

/*
* (a) 有。首先 'a' 提升为 int，然后与 3 相加，接着结果从 int 转为 char 赋值给 cval。
* (b) 有。ival 从 int 转为 double 与 1.0 做乘法，ui 从 unsigned int 转为 double 与之前的结果做减法，整个结果转为 float 赋值给 fval。
* (c) 有。ui 转为 float 与 fval 做乘法，然后结果转为 double 赋值给 dval。
* (d) 有。ival、fval 都转为 double 类型，最后结果转为 char 类型赋值给 cval。
*/
