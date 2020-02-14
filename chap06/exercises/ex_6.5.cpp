//练习 6.5：编写一个函数输出其实参的绝对值。

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

double mAbs(double n) {
    return n < 0 ? -n : n;
}

int main() {
    double val = 0;
    cout << "输入一个数：";
    if (cin >> val) {
        cout << "|" << val << "| = " << mAbs(val) << endl;
    }

    return 0;
}
