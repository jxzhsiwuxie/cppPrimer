//练习 6.16：下面的这个函数虽然合法，但是不是特别有用。指出它的局限性并设法改善。
// bool is_empty(string &s){return s.empty();}

/*
* 函数的形参是普通引用，导致函数不能接收常量类型的 string 和字符串字面值。
* 鉴于函数内部并不需要修改实参的值，这里可以改为：
*/
// bool is_empty(const string &s){return s.empty();}
