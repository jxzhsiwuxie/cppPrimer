//练习 16.64：为上一题的模板编写特例化的版本来处理 vecotr<const char *>。编写程序使用这个特例化版本。

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using std::count_if;
using std::cout;
using std::endl;
using std::string;
using std::vector;

template <typename T>
unsigned countElem(const vector<T> &container, const T &item) {
    return count_if(container.begin(), container.end(), [=](const T &e) { return e == item; });
}

template <>
unsigned countElem(const vector<const char *> &container, const char *const &item) {
    return count_if(container.begin(), container.end(), [=](const char *e) { return std::strcmp(e, item) == 0; });
}

int main() {
    vector<int> ivec = {1, 1, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4};
    vector<double> dvec = {1.0, 1.0, 2.0, 2.0, 2.0, 3.0, 3.0, 3.0, 3.0, 4.0, 4.0, 4.0, 4.0, 4.0};
    vector<string> svec = {"aa", "aa", "bbb", "bbb", "bbb", "cccc", "cccc", "cccc", "cccc"};
    vector<const char *> cvec = {"aa", "aa", "bbb", "bbb", "bbb", "cccc", "cccc", "cccc", "cccc"};

    cout << countElem(ivec, 2) << endl;
    cout << countElem(dvec, 3.0) << endl;
    cout << countElem(svec, string("cccc")) << endl;

    const char *cptr = "cccc";
    cout << countElem(cvec, cptr) << endl;

    return 0;
}
