//练习 17.35：修改第 670 页中的程序，打印 2 的平方根，但这次打印十六进制的大写形式。

#include <cmath>
#include <iostream>

using std::cout;
using std::defaultfloat;
using std::endl;
using std::hexfloat;
using std::nouppercase;
using std::uppercase;
using std::sqrt;

int main() {
    cout << hexfloat << uppercase << sqrt(2) << endl;
    cout << defaultfloat << nouppercase << sqrt(2) << endl;

    return 0;
}
