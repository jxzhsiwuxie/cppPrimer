//练习 11.30：对于本节最后一个程序中的输出表达式，解释运算对象 pos.forst->second 的含义。

/*
* pos.forst->second：
* pos.first 得到 equal_range 返回的 pair 的第一个迭代器，是一个指向 authors 关键字为 serch_item 的元素（pair<string, string>），
* pos.first->second 得到关键字为 serch_item 对应的值。
*/
