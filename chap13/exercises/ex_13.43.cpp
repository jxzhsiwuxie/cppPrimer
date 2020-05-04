//练习 13.43：重写 free 成员，用 for_each 和 lambda（参见 10.3.2 节，第 346 页）来代替 for 循环 destroy 元素。
//你更倾向于哪种实现，为什么？

/*
* 更倾向于使用 for_each 和 lambda 的实现方式。
* 一方面更加的直观，另一方面页更加的通用。
*/

#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>

#include "StrVec.h"

using std::copy;
using std::cout;
using std::endl;
using std::ostream_iterator;
using std::string;

int main() {
    StrVec svec;
    cout << "size = " << svec.size() << ", capacity = " << svec.capacity() << endl;
    svec.push_back("dads");
    svec.push_back("yretytg");

    cout << "size = " << svec.size() << ", capacity = " << svec.capacity() << endl;

    ostream_iterator<string> os_iter(cout, " ");
    copy(svec.begin(), svec.end(), os_iter);

    return 0;
}
