//练习 6.3：编写你自己的 fact 函数，上机检查是否正确。

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
