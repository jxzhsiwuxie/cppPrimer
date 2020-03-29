//练习 10.1：头文件 algorithm 中定义了一个名为 count 的函数，它类似 find，接受一个迭代器和一个值作为参数/
//count 返回给定的值在序列中出现的次数。编写程序，读取 int 序列存入 vector 中，打印有多少个值等于给定的值。

#include <algorithm>
#include <ctime>
#include <iostream>
#include <random>
#include <vector>

using std::default_random_engine;
using std::normal_distribution;       //正态分布
using std::uniform_int_distribution;  //均匀分布

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main() {
    default_random_engine e(std::time(NULL));
    normal_distribution<double> dis(16, 8);
    uniform_int_distribution<int> u(0, 32);

    vector<int> ivec;
    for (int i = 0; i < 64; ++i)
        ivec.push_back(dis(e));

    cout << "vector 中包含的所有数字为：" << endl;
    for (const auto n : ivec)
        cout << n << " ";
    cout << endl;

    int val = -1;
    cout << "输入一个想要查找的数字（0~32）：";
    if (cin >> val) {
        auto result = std::count(ivec.cbegin(), ivec.cend(), val);

        cout << "找到数字 " << val << " 的个数为：" << result << " 个" << endl;
    }

    return 0;
}
