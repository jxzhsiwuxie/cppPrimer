//练习 16.63：定义一个函数模板，统计一个给定值在一个 vector 中出现的次数。测试你的函数，
//分别传递给它一个 double 的 vector，一个 int 的 vector 以及一个 string 的 vector。

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::count_if;
using std::cout;
using std::endl;
using std::string;
using std::vector;

template <typename T>
unsigned countElem(const vector<T> &container, const T &item) {
    return count_if(container.begin(), container.end(), [=](const T &e) {return e == item; });
}

int main() {
    vector<int> ivec = {1, 1, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4};
    vector<double> dvec = {1.0, 1.0, 2.0, 2.0, 2.0, 3.0, 3.0, 3.0, 3.0, 4.0, 4.0, 4.0, 4.0, 4.0};
    vector<string> svec = {"aa", "aa", "bbb", "bbb", "bbb", "cccc", "cccc", "cccc", "cccc"};

    cout << countElem(ivec, 2) << endl;
    cout << countElem(dvec, 3.0) << endl;
    cout << countElem(svec, string("cccc")) << endl;

    return 0;
}