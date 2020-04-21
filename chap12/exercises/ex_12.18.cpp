//练习 12.18：shared_ptr 为什么没有 release 成员？

/*
* 对于 unique_ptr 来说，成员 release 的功能是该智能指针放弃对内置指针的控制权，将内置指针返回同时将智能指针指向空。
* 一方面返回内置指针通过 shared_ptr 的 get 成员即可实现，而且 shared_ptr 对于内置指针是共享而不是独占的，所以如果希望将它的计数减一只要一个值例如 nullptr 赋给它就行了。
*/
