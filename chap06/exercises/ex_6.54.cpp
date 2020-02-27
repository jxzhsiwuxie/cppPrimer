//练习：6.54：编写函数的声明，令其接收两个 int 形参并且其返回类型也是 int；
//然后声明一个 vector 对象，令其元素是指向该函数的指针。

#include <iostream>
#include <vector>
#include <cstddef>

using std::cout;
using std::endl;
using std::vector;
using std::size_t;

int f(int, int);

//定义函数类型和函数指针类型
typedef int f1(int, int);
typedef int (*pf1)(int, int);

//与上面等价的定义
using f2 = int(int, int);
using pf2 = int (*)(int, int);

int main() {
    //定义函数指针变量，可以用 f 初始化也可以用 &f 初始化，
    //两者没区别。
    f1 *pf10 = f;
    pf1 pf11 = f;

    f2 *pf20 = &f;
    pf2 pf21 = &f;

    decltype(f) *pf30 = f;
    decltype(pf10) pf31 = f;

    vector<pf1> pfVec = {pf10, pf11, pf20, pf21, pf30, pf31};
    for (decltype(pfVec.size()) i = 0; i != pfVec.size(); ++i)
        pfVec.at(i)(i, i);  //通过函数指针调用函数

    return 0;
}

int f(int a, int b) {
    cout << "调用了函数 int f(int, int)，返回值为：" << a + b << endl;
    return a + b;
}
