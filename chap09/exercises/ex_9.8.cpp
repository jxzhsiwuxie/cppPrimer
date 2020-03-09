//练习 9.8：为了读取 string 的 list 中的元素，应该使用什么类型？如果写入 list，又该使用什么类型？

/*
* 读取 string 的 list 可以使用 list<string>::const_iterator 和 list<string>::const_reference 两种类型；
* 写入 string 的 list 可以使用 list<string>::iterator 和 list<string>::reference 两种类型。
*/
