//练习 7.36：下面的初始值是错误的，请找出问题所在并尝试修改它。
// struct X {
//     X(int i, int j) : base(i), rem(base % j) {}
//     int rem, base;
// };

/*
* 构造函数初始化列表在初始化数据成员时并不会按照列表排列的顺序来初始化各个成员，而是
* 按照成员在类中出现的顺序来依次初始化。
* 从定义可以看出，成员 rem 先于 base 出现，所以在初始化列表中 rem 总是先于 base 被初始化的，
* 因而 rem(base % j) 此时 base 还未定义，所以这个初始化结果是错误的。
*/

#include <iostream>

struct X {
    X(int i, int j) : base(i), rem(base % j) {}
    int rem, base;
};

int main() {
    X xObj(8, 5);

    std::cout << "原本是希望 base = 8, rem = 3。但实际上：" << std::endl;

    std::cout << "           base = " << xObj.base << ", rem = " << xObj.rem << std::endl;

    return 0;
}
