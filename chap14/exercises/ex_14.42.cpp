//练习 14.42：使用标准库函数对象及适配器定义一条表达式，令其
//（a）统计大于 1024 的值有多少个。
//（b）找到第一个不等于 pooh 的字符串。
//（c）将所有的值乘以 2。

#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using namespace std::placeholders;

int main() {
    vector<int> ivec = {3213, 213, 13, 21, 23, 12, 321, 323, 21423424, 23, 442};
    int c = std::count_if(ivec.begin(), ivec.end(), std::bind(std::greater<int>(), _1, 1024));
    cout << c << endl;

    vector<string> svec = {"pooh", "pooh", "pooh", "hkhk", "pooh", "pooh"};
    auto iter = std::find_if(svec.cbegin(), svec.cend(), std::bind(std::not_equal_to<string>(), _1, "pooh"));
    cout << *iter << endl;

    vector<int> ivec2 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> ivec3(ivec2.size());
    std::transform(ivec2.begin(), ivec2.end(), ivec3.begin(), std::bind(std::multiplies<int>(), _1, 2));
    for (const auto n : ivec3)
        cout << n << '\t';
    cout << endl;

    return 0;
}
