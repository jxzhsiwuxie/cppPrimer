//练习 13.12：在下面的代码片段中会发生几次析构函数调用？
// bool func(const Sales_data *trans, Sales_data accum)
// {
//      Sales_data item1(*trans), item2(accum);
//      return item1.isbn() != item2.isbn();
// }

/*
* item1、item2、item1 的 bookNo、item2 的 bookNo、accum 以及 accum 的 bookNo 总共 6 次。
*/
