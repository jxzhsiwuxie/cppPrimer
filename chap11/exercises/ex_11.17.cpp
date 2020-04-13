//练习 11.17：假定 c 是一个 string 的 multiset，v 是一个 string 的 vector，解释下面的调用。指出每个调用是否合法：
// (1) copy(v.begin(), v.end(), inserter(c, c.end()))
// (2) copy(v.begin(), v.end(), back_inserter(c))
// (3) copy(c.begin(), c.end(), inserter(v, v.end()))
// (4) copy(c.begin(), c.end(), back_inserter(v))

/*
* (1) 合法。
* (2) 不合法（multiset 没有 push_back）。
* (3) 合法。
* (4) 合法。
*/

#include <iostream>
#include <iterator>
#include <set>
#include <string>
#include <vector>

using std::back_inserter;
using std::cout;
using std::endl;
using std::inserter;
using std::multiset;
using std::string;
using std::vector;

int main() {
    multiset<string> c0 = {"abc", "def", "hij"};
    vector<string> v0 = {"klm", "nop", "qrs"};

    multiset<string> c1, c2;
    vector<string> v1, v2;

    cout << "c0 中元素：" << endl;
    for (const auto &s : c0)
        cout << s << " ";
    cout << endl;
    cout << "-------------------------" << endl;

    cout << "v0 中元素：" << endl;
    for (const auto &s : v0)
        cout << s << " ";
    cout << endl;
    cout << "-------------------------" << endl;

    copy(v0.begin(), v0.end(), inserter(c1, c1.end()));
    cout << "c1 中元素：" << endl;
    for (const auto &s : c1)
        cout << s << " ";
    cout << endl;
    cout << "-------------------------" << endl;

    // copy(v0.begin(), v0.end(), back_inserter(c2));
    // cout << "c2 中元素：" << endl;
    // for (const auto &s : c2)
    //     cout << s << " ";
    // cout << endl;
    // cout << "-------------------------" << endl;

    copy(c0.begin(), c0.end(), inserter(v1, v1.end()));
    cout << "v1 中元素：" << endl;
    for (const auto &s : v1)
        cout << s << " ";
    cout << endl;
    cout << "-------------------------" << endl;

    copy(c0.begin(), c0.end(), back_inserter(v2));
    cout << "v2 中元素：" << endl;
    for (const auto &s : v2)
        cout << s << " ";
    cout << endl;
    cout << "-------------------------" << endl;

    return 0;
}
