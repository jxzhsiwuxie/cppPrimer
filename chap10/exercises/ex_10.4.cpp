//练习 10.4：假定 v 是一个 vector<double>，那么调用 accumulate(v.cbegin(), v.cend(), 0) 有何错误（如果存在的话）？

/*
* accumulate 在计算时会将序列中元素的类型转换为第三个参数的类型。
* 所以这里再求值时第三个参数 0 是一个 int 类型，这样每次累加的时候都会将 v 中的 double 元素先转换为 int 然后再相加导致错误。
* 实际上第三个参数应该为 0.0。
*/

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

    vector<double> ivec;
    for (int i = 0; i < 64; ++i)
        ivec.push_back(ndis(e));

    cout << "vector 中包含的所有数字为：" << endl;
    for (const auto n : ivec)
        cout << n << " ";
    cout << endl;

    //如果第三个参数不是 0.0 而是 0 的话，得到的 result 将会是 int 类型。
    auto result = accumulate(ivec.cbegin(), ivec.cend(), 0.0);

    cout << "所有数字和为： " << result << endl;

    return 0;
}
