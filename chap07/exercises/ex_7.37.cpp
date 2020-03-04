//练习 7.37：使用本节提供的 Sales_data 类，确定初始化下面变量时分别使用了哪个构造函数，
//然后罗列出每个对象所有数据成员的值。
// Sales_data first_item(cin);
// int main() {
//     Sales_data next;
//     Sales_data last("9-999-99999-9");
// }

/*
* 本节 Sales_data 类的构造函数：
*/
// class Sales_data {
//     public:
//     Sales_data(std::string s = ""): bookNo(s) { }
//     Sales_data(std::string s, unsigned cnt, double rev): bookNo(s), units_solid(cnt), revenue( rev * cnt) { }
//     Sales_data(std::istream &is) { read(is, *this); }
// };

/*
* （1）Sales_data first_item(cin); 使用了 Sales_data(std::istream &is) { read(is, *this); }
* bookNo 值为从输入流中读取到的字符串，units_solid 为从输入流中读取到的第一个数字，revenue 为从输入流中读取到的第一个 double 值与 units_solid 的乘积。
* （2）Sales_data next; 使用了 Sales_data(std::string s = ""): bookNo(s) { }
* bookNo 为""，units_solid 0，revenue 0。
* （3）Sales_data last("9-999-99999-9"); 使用了 Sales_data(std::string s = ""): bookNo(s) { }
* bookNo 为"9-999-99999-9"，units_solid 0，revenue 0。
*/
