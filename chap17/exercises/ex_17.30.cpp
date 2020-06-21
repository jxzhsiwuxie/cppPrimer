//练习 17.30：再次修改你的程序，此次再增加两个参数，，表示函数允许返回的最大值和最小值。

#include <ctime>
#include <iostream>
#include <random>

using std::cin;
using std::cout;
using std::default_random_engine;
using std::endl;
using std::time;
using std::uniform_int_distribution;

unsigned getUInt(const unsigned seed, const unsigned min, const unsigned max) {
    static default_random_engine e(seed);
    static uniform_int_distribution<unsigned> uiDis(min, max);

    return uiDis(e);
}

int main() {
    unsigned seed = 0, min, max;
    cout << "输入一个整数作为种子：";
    cin >> seed;
    cout << "输入随机数的上限：";
    cin >> max;
    cout << "输入随机数的下限";
    cin >> min;

    cout << getUInt(seed, min, max) << endl;
    cout << getUInt(seed, min, max) << endl;
    cout << getUInt(seed, min, max) << endl;
    cout << getUInt(seed, min, max) << endl;

    return 0;
}
