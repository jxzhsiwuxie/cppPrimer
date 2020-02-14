//练习 6.4：编写一个与用户交互的函数，要求用户输入一个数字，计算该数字生成的阶乘。在 main 函数中调用这个函数。

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int fact(int n) {
    if (n == 0)
        return 1;
    else {
        int ret = 1;
        while (n > 0)
            ret *= n--;
        return ret;
    }
}

int main() {
    int val = 0;
    cout << "输入一个正整数：";
    if (cin >> val && val >= 0) {
        cout << val << "! = " << fact(val) << endl;
    }

    return 0;
}
