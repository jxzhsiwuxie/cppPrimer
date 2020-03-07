//练习 7.48：假定 Sales_data 的构造函数不是 explicit 的，则下述定义将执行什么样的操作？
// string null_isbn("9-999-99999-9");
// Sales_data item1(null_isbn);
// Sales_data item2("9-999-99999-9");
// 如果 Sales_data 的构造函数是 explicit 的，则又会发生什么？

/*
* 如果 Sales_data 的构造函数不是 explicit 的，则上面三局定义中的后两句作用是一样的，
* 都是调用一个 string 参数的构造函数创建一个 Sales_data 对象。
* 如果 Sales_data 的构造函数是 explicit 的，则上面三局定义中的第二句是正确的，而第三句是错误的。
*/
