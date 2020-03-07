//练习 7.49：对于 combine 函数的三种不同声明，但我们调用 i.combine(s) 时分别发生什么情况？
//其中 i 是一个 Sales_data 而 s 是一个 string 对象。
// (a) Sales_data &combine(Sales_data);
// (b) Sales_data &combine(Sales_data&);
// (c) Sales_data &combine(const Sales_data&) const;

/*
* 如果 Sales_data 的只包含一个 string 参数的构造函数是 explicit 的，则 i.combine(s) 是错误的，否则
* (a) 首先利用 s 创建一个临时的 Sales_data 对象，然后利用这个临时对象初始化 s。
* (b) 首先利用 s 创建一个临时的 Sales_data 对象，然后将 s 绑定到这个临时对象上。
* (c) 这个函数无法定义，因为 combine 内部会修改调用对象。
*/
