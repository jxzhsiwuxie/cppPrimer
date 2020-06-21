//练习 17.29：修改上一题中编写的函数，允许用户提供一个种子最为可选参数。

#include <ctime>
#include <iostream>
#include <random>

using std::cin;
using std::cout;
using std::default_random_engine;
using std::endl;
using std::time;
using std::uniform_int_distribution;

unsigned getUInt(const unsigned seed = 0) {
    static default_random_engine e(seed);
    static uniform_int_distribution<unsigned> uiDis;

    return uiDis(e);
}

int main() {
    unsigned seed = 0;
    cout << "输入一个整数作为种子：";
    cin >> seed;

    cout << getUInt(seed) << endl;
    cout << getUInt(seed) << endl;
    cout << getUInt(seed) << endl;
    cout << getUInt(seed) << endl;

    return 0;
}
