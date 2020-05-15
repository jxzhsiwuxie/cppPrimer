//练习 14.43：使用标准库函数对象判断一个给定的 int 值是否能被 int 容器中的所有元素整除。

#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using namespace std::placeholders;

int main() {
    vector<int> ivec = {3213, 213, 13, 21, 23, 12, 321, 323, 21423424, 23, 442};
    int t = 11;
    auto iter = std::find_if(ivec.cbegin(), ivec.cend(), std::bind(std::modulus<int>(), _1, t));
    cout << (iter == ivec.cend() ? "都可以被整除" : "不能都被整除") << endl;

    return 0;
}
