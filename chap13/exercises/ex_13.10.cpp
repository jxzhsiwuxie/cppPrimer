//练习 13.10：当一个 StrBlob 对象销毁时会发生什么？一个 StrBlobPtr 对象销毁时呢？

/*
* 当一个 StrBlob 对象销毁时，将会调用它的合成析构函数。销毁 shared_ptr 类型的成员 data。
* data 再调用 shared_ptr 类的析构函数，销毁它所管理的对象。
*/

/*
* 当一个 StrBlobPtr 对象销毁时，将会调用它的合成析构函数。首先销毁 weak_ptr 类型的成员 wptr。
* 接着再销毁 curr 成员。
*/
