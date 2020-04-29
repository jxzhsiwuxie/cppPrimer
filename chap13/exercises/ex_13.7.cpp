//练习 13.7：当我们将一个 StrBlob 赋值给另一个 StrBlob 时会发生什么？赋值 StrBlobPtr 呢？

/*
* 将一个 StrBlob 赋值给另一个 StrBlob 时会调用它的合成拷贝赋值运算符。通过调用 shared_ptr 的拷贝赋值云南算符将右侧对象的 data 成员赋值给左侧左侧对象的 data 成员。
*/

/*
* 将一个 StrBlobPtr 赋值给另一个 StrBlobPtr 时会调用它的合成拷贝赋值运算符。通过调用 weak_ptr 的拷贝赋值云南算符将右侧对象的 wptr 成员赋值给左侧左侧对象的 wptr 成员，
* 将左侧对象的 curr 成员直接赋值给右侧对象的 curr 成员。
*/
