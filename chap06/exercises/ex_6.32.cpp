//练习 6.32：下面的函数合法么？如果合法，说明其功能；如果不合法，修改其中的错误并说明原因。
// int &get(int *arr, int index) { return arr[index]; }
// int main() {
//     int ia[10];
//     for (int i = 0; i != 10; ++i)
//         get(ia, i) = i;
// }

/*
* 合法。
* 返回数组中索引为 index 元素的引用。
*/

#include <iostream>

int &get(int *arr, int index) { return arr[index]; }
int main() {
    int ia[10];
    for (int i = 0; i != 10; ++i)
        get(ia, i) = i;

    for (auto i : ia)
        std::cout << i << " ";
}
