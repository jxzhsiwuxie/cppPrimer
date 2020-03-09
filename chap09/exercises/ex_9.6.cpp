//练习 9.6：下面程序有何错误？你应该如何让修改它？
// list<int> lst1;
// list<int>::iterator iter1 = lst1.begin(), iter2 = lst1.endd();
// while (iter1 < iter2) /* ... */

/*
* list<int>::iterator 迭代器不支持小于运算符，改用不等于即可。
*/

// list<int> lst1;
// list<int>::iterator iter1 = lst1.begin(), iter2 = lst1.endd();
// while (iter1 != iter2) /* ... */
