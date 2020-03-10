//练习 9.22：假设 iv 是一个 int 的 vector，下面的程序存在什么错误？你将如何修改？
// vector<int>::iterator iter = iv.begin(), mid = iv.begin() + iv.size() / 2;
// while (iter != min)
//     if(*iter == some_value)
//         iv.insert(iter, 2 * some_value);

/*
* 向 vector 插入元素会使所有指向容器的迭代器、指针和引用失效。
* 另外，在循环中也没有更新 iter，导致循环无法退出。
* 所以上面的程序在循环中向 vector 中插入元素，同时又利用原本的迭代器来控制循环，显然可能造成错误。
* 可以使用一个临时 vector 来解决。
*/

// vector<int>::iterator iter = iv.begin(), mid = iv.begin() + iv.size() / 2;
// vector<int> tempVec;
// while (iter != min) {
//     if(*iter == some_value)
//         tempVec.push_back(2 * some_value);
//     else
//         tempVec.push_back(*iter);
//     ++iter;
// }
// while (min != iv.end())
//     tempVec.push_back(*mid++);
// iv = tempVec;
