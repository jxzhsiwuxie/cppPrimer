//练习 3.27：假设 txt_size 是一个无参数的函数，它的返回值是 int。请回答下列哪个定义是非法的？为什么？
/*
* unsigned buff_size = 1024;
* (a) int ia[buff_size];            (b) int ia[4 * 7 - 14];
* (c) int ia[txt_size()];           (d) char st[11] = "fundamental";
*/

/*
* (a) 非法，buff_size 不是一个常量表达式，不能用于数组的维度。
* (b) 合法。
* (c) txt_size 是 constexpr 时是合法的否则是非法的。
* (d) 非法的。字符串字面值默认包含一个空字符 '\0'，"fundamental" 实际包含 12 个字符，不能存入 st 中。
*/