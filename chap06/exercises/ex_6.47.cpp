//练习 6.47：改写 6.3.2 节练习中使用递归输出 vector 内容的程序，使其有条件地输出与执行过程有关的信息。
//例如，每次调用时输出 vector 对象的大小。分别在打开和关闭调试器的情况下编译并执行这个程序。

#include <cassert>
#include <iostream>
#include <vector>

//调试器开关
#define NDEBUG

using std::cout;
using std::endl;
using std::vector;

void printVector(vector<int>::iterator beg, vector<int>::iterator end) {
    if (beg == end) {
        cout << endl;

        #ifndef NDEBUG
                cout << "当前 vector 对象的大小为：" << sizeof(int) * (end - beg) << " bytes" << endl;
        #endif

        return;
    }

    cout << *beg++ << " ";
    #ifndef NDEBUG
        cout << "当前 vector 对象的大小为：" << sizeof(int) * (end - beg) << " bytes" << endl;
    #endif

    printVector(beg, end);
}

int main() {
    vector<int> ivec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    printVector(ivec.begin(), ivec.end());

    return 0;
}
