//练习 6.18：为下面的函数编写函数声明，从给定的名字中推测函数具备的功能。
// (a) 名为 compare 的函数，返回布尔值，两个参数都是 matrix 类的引用。
// (b) 名为 change_val 的函数，返回 vector<int> 的迭代器，有两个参数：一个是 int，另一个是 vector<int> 的迭代器。

/*
* (a) compare 函数应该是比较两个 matrix 类型对象，但是具体比较规则未知，函数声明如下：
*/
// bool compare(const matrix &m1, const matrix &m2);

/*
* (b) change_val 函数应该是修改指定迭代器所指元素的值，函数声明如下：
*/
// vector<int>::iterator change_val(int n, vector<int>::iterator it);


