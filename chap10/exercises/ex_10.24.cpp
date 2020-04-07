//练习 10.24：给定一个 string，使用 bind 和 check_size 在一个 int 的 vector 中查找第一个大于 string 长度的值。

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

bool check_size(const string &s, string::size_type sz) {
    return s.size() < sz;
}

int main() {
    vector<int> ivec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    string str("abc");

    auto it = std::find_if(ivec.begin(), ivec.end(), std::bind(check_size, str, _1));

    if (it != ivec.end())
        cout << "ivec 中第一个大于 str 长度的值是：" << *it << endl;
    else
        cout << "ivec 中没有大于 str 长度的值" << endl;

    return 0;
}
