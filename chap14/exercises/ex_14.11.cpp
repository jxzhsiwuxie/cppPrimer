//练习 14.11：下面的 Sales_data 输入运算符存在错误么？如果有请指出来。对于这个输入运算符，
//如果仍给定上个练习的输入将发生什么情况？
// istream& operator>>(istream &in, Sales_data &s){
//     double price;
//     in >> s.bookNo >> s.units_solid >> price;
//     s.revenue = s.units_solid * price;
//     return in;
// }

/*
* 没有处理输入发生错误的情况。
* 按照上题 (a) 的输入，能够得到预期的结果，
* 按照上题 (b) 的输入，得到一个价格为 0 的对象。
*/
