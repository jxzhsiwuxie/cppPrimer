//练习 13.2：解释为什么下面的声明是非法的：
// Sales_data::Sales_data(Sales_data rhs);

/*
* 例如在调用形参为非引用类型的 Sales_data 函数时，传入的实参是一个 Sales_data 变量，则会匹配到上述声明的函数，
* 此时调用将会无限持续下去导致错误。
*/
