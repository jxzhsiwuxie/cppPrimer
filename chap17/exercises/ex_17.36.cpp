//修改上一题中的程序，打印不同的浮点数，使它们排成一列。

#include <cmath>
#include <iostream>
#include <iomanip>

using std::cout;
using std::setw;
using std::endl;
using std::sqrt;
using std::left;
using std::right;
using std::setfill;
using std::showpoint;
using std::noshowpoint;


int main() {
    cout << left << showpoint
        << setw(16) << setfill('*') << sqrt(1) << '\n'
        << setw(16) << setfill('*') << sqrt(2) << '\n'
        << setw(16) << setfill('*') << sqrt(3) << '\n'
        << setw(16) << setfill('*') << sqrt(4) << '\n'
        << setw(16) << setfill('*') << sqrt(5) << '\n'
        << right << noshowpoint << endl;

    return 0;
}
