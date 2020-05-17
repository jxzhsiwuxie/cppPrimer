//练习 14.51：在调用 calc 的过程中，可能用到哪些类型转换序列呢？说明最佳可行函数时如何被选出来的。
// void calc(int);
// void calc(LongDouble);
// double dval;
// calc(dval);

/*
* 使用 void calc(int); 隐式地从 double 转换为 int；
* 使用 void calc(LongDouble); 隐式地从 double 转换为 LongDouble。
* 转换过程包含标准类型转换，并且用户定义地类型转换只有一个，所以标准类型转换地级别决定了最佳匹配。
* 这里 calc(dval); 最终调用的是 void calc(int);
*/

