//练习 9.37：为什么 list 和 array 没有 capacity 成员函数？

/*
* list 以链表形式存储元素，元素并不需要存储在一块连续的内存中，所以也就不需要 capacity 概念。
* array 的元素数目是固定无法改变的，所以也不需要 capacity 概念。
*/
