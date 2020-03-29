//练习 10.2：重做上一题，但读取 string 序列存入 list 中。

#include <algorithm>
#include <ctime>
#include <iostream>
#include <list>
#include <random>
#include <string>
#include <vector>

using std::default_random_engine;
using std::normal_distribution;       //正态分布
using std::uniform_int_distribution;  //均匀分布

using std::list;
using std::string;

using std::cin;
using std::cout;
using std::endl;

int main() {
    default_random_engine e(std::time(NULL));
    normal_distribution<double> ndis(16, 8);
    uniform_int_distribution<int> udis(0, 32);

    const string temp = "abcdefghijklmnopqrstuvwxyz";

    list<string> slst;
    for (int i = 0; i < 64; ++i)
        slst.push_back(temp.substr(static_cast<unsigned>(ndis(e)) % 26, 1));

    cout << "list 中包含的所有字符为：" << endl;
    for (const auto n : slst)
        cout << n << " ";
    cout << endl;

    string val;
    cout << "输入一个想要查找的字符（a~z）：";
    if (cin >> val) {
        auto result = std::count(slst.cbegin(), slst.cend(), val);

        cout << "找到字符 " << val << " 的个数为：" << result << " 个" << endl;
    }

    return 0;
}
