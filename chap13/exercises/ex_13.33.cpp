//练习 13.33：为什么 Message 的成员 save 和 remove 的参数是一个 Folder&？
//为什么我们不将参数定义为 Folder 或是 const Folder&？

/*
* 如果定义为 Folder 则函数内部使用的 f 就是实参的拷贝版本，其地址与传进去的实参的地址是不一样的。
* 如果将参数定义为 const Folder&，则函数内部无法修改 f，也就不能调用 f 的 addMsg 成员了。
*/
