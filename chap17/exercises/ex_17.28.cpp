//练习 17。28：编写函数，每次调用生成并返回一个均匀分布的随机 unsigned int。

#include <ctime>
#include <iostream>
#include <random>

using std::cout;
using std::default_random_engine;
using std::endl;
using std::time;
using std::uniform_int_distribution;

unsigned getUInt() {
    static default_random_engine e(time(nullptr));
    static uniform_int_distribution<unsigned> uiDis;

    return uiDis(e);
}

int main() {
    cout << getUInt() << endl;
    cout << getUInt() << endl;
    cout << getUInt() << endl;
    cout << getUInt() << endl;

    return 0;
}
