//练习 10.3：利用 accumulate 求一个 vector<int> 中的元素之和。

#include <algorithm>
#include <ctime>
#include <iostream>
#include <numeric>
#include <random>
#include <vector>

using std::default_random_engine;
using std::normal_distribution;  //正态分布

using std::accumulate;
using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main() {
    default_random_engine e(std::time(NULL));
    normal_distribution<double> ndis(0, 4);

    vector<int> ivec;
    for (int i = 0; i < 64; ++i)
        ivec.push_back(ndis(e));

    cout << "vector 中包含的所有数字为：" << endl;
    for (const auto n : ivec)
        cout << n << " ";
    cout << endl;

    auto result = accumulate(ivec.cbegin(), ivec.cend(), 0);

    cout << "所有数字和为： " << result << endl;

    return 0;
}
