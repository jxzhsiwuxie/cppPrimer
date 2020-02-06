//练习 4.29：判断下面代码输出的结果，并说明理由。实际运行这段程序，
//结果和你想象的一样么？如果不一样，为什么？
// int x[10]; int *p = x;
// cout << sizeof(x) / sizeof(*x) << endl;
// cout << sizeof(p) / sizeof(*p) << endl;

/*
* 第一句输出数组 x 的元素个数 10，
* 第二句输出指针所占空间大小除以 int 类型所占空间大小，结果为 2。
*/

#include <iostream>

int main() {
    using std::cout;
    using std::endl;

    int x[10];
    int *p = x;
    cout << sizeof(x) / sizeof(*x) << endl;
    cout << sizeof(p) / sizeof(*p) << endl;

    cout << sizeof(p) << endl;  //当前电脑上指针占 8 字节

    return 0;
}
