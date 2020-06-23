//练习 17.34：编写一个程序，展示如何使用表 17.17 和表 17.18 中的每个操纵符。

#include <iomanip>
#include <iostream>

using std::cout;
using std::endl;

//将 true 和 false 输出为字符串而非 1/0
using std::boolalpha;
using std::noboolalpha;
//显式整型值的进制
using std::noshowbase;
using std::showbase;
//显式浮点数的小数点
using std::noshowpoint;
using std::showpoint;
//对非负数显式 +
using std::noshowpos;
using std::showpos;
//十六进制显式大写 0X，，科学计数法显式大写 E
using std::nouppercase;
using std::uppercase;
//整型值显式为十进制、十六进制、八进制
using std::dec;
using std::hex;
using std::oct;
//在值的右侧、左侧或者符号和值之间添加填充字符
using std::internal;
using std::left;
using std::right;
//浮点值显式为定点十进制
using std::fixed;
//浮点值显式为科学计数法
using std::scientific;
//浮点值显式为十六进制
using std::hexfloat;
//重置浮点值为十进制
using std::defaultfloat;

//使用特定字符填充空白
using std::setfill;
//将浮点精度设置为 n
using std::setprecision;
//读或写宽度为 w 个字符
using std::setw;
//将整数输出为 b 进制
using std::setbase;

int main() {
    cout << boolalpha << "使用 boolalpha，true = " << true << "; false = " << false << endl;
    cout << noboolalpha << "未使用 boolalpha，true = " << true << "; false = " << false << endl;

    cout << "---------------------------------" << endl;
    cout << hex << showbase << "使用 showbase，100 = " << 100 << endl;
    cout << dec << noshowbase << "未使用 showbase，100 = " << 100 << endl;

    cout << "---------------------------------" << endl;
    cout << setfill('*') << setw(16) << -123 << endl;
    cout << setfill('*') << setw(16) << left << -123 << endl;
    cout << setfill('*') << setw(16) << internal << -123 << right << endl;

    cout << "---------------------------------" << endl;
    cout << setprecision(16) << fixed << 1.23456 << endl;
    cout << setprecision(16) << scientific << 1.23456 << endl;
    cout << setprecision(16) << hexfloat << 1.23456 << endl;
    cout << setprecision(16) << defaultfloat << 1.23456 << endl;


    return 0;
}
