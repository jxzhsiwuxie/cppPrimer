//练习 6.55：编写 4 个函数，分别对两个 int 执行加、减、乘、除运算；在上一题创建的 vector 对象中保存指向这些函数的指针。

#include <cctype>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int add(int a, int b) { return a + b; }
int substract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
int divide(int a, int b) {
    if (b)
        return a / b;
    else
        throw "除数不可以为 0。";
}

using iiiPFunc = int (*)(int, int);

bool isStringNumber(const string &);

int main() {
    vector<iiiPFunc> pfVec;
    pfVec.push_back(add);
    pfVec.push_back(substract);
    pfVec.push_back(multiply);
    pfVec.push_back(divide);

    cout << "输入一个整数算式（数字与符号用空格隔开例如：12 * 20）" << endl;

    int a, b;
    char op;

    if (cin >> a >> op >> b) {
        switch (op) {
            case '+':
                cout << a << " + " << b << " = " << pfVec.at(0)(a, b) << endl;
                break;
            case '-':
                cout << a << " - " << b << " = " << pfVec.at(1)(a, b) << endl;
                break;
            case '*':
                cout << a << " * " << b << " = " << pfVec.at(2)(a, b) << endl;
                break;
            case '/':
                cout << a << " / " << b << " = " << pfVec.at(3)(a, b) << endl;
                break;
            default:
                break;
        }
    } else {
        cout << "输入算式无效" << endl;
    }

    return 0;
}

bool isStringNumber(const string &s) {
    bool res = true;
    for (const auto c : s) {
        if (!std::isdigit(c)) {
            res = false;
            break;
        }
    }
    return res;
}
