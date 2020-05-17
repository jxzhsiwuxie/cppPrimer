//练习 14.44：编写一个简单的桌面计算器，使其能处理二元运算。

#include <functional>
#include <iostream>
#include <map>
#include <string>

using std::cout;
using std::endl;
using std::function;
using std::map;
using std::string;

int add(int i, int j) { return i + j; }
auto min = [](int i, int j) { return i - j; };
struct mult {
    int operator()(int i, int j) { return i * j; }
};

int main() {
    map<string, function<int(int, int)>> calcu = {
        {"+", add}, {"-", min}, {"*", mult()}, {"/", std::divides<int>()}};

    cout << "1 + 2 = " << calcu.at("+")(1, 2) << endl;
    cout << "1 - 2 = " << calcu.at("-")(1, 2) << endl;
    cout << "1 * 2 = " << calcu.at("*")(1, 2) << endl;
    cout << "1 / 2 = " << calcu.at("/")(1, 2) << endl;

    return 0;
}
