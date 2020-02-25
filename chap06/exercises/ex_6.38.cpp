//练习 6.38：修改 arrPtr 函数，使其返回数组的引用。

/*
* 原本返回指向数组的指针的函数
*/
// int odd[] = {1, 3, 5, 7, 9};
// int even[] = {0, 2, 4, 6, 8};

// decltype(odd) *arrPtr(int i) {
//     return (i % 2) ? &odd : &even;
// }

/*
* 修改后
*/

int odd[] = {1, 3, 5, 7, 9};
int even[] = {0, 2, 4, 6, 8};

decltype(odd) &arrPtr(int i) {
    return (i % 2) ? odd : even;
}
