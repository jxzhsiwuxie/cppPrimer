//练习 10.37：给定一个包含 10 个元素的 vector，将位置 3 到 7 之间的元素按逆序拷贝到一个 list 中。

#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>

using std::copy;
using std::cout;
using std::endl;
using std::list;
using std::vector;

using std::front_inserter;
using std::back_inserter;

int main() {
    vector<int> ivec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    list<int> ilst;

    cout << "vector 中包含的元素为：" << endl;
    for (const auto n : ivec)
        cout << n << " ";
    cout << endl;

    // copy(ivec.crbegin() + 3, ivec.crbegin() + 8, back_inserter(ilst));
    copy(ivec.cbegin() + 2, ivec.cbegin() + 7, front_inserter(ilst));

    cout << "拷贝之后 list 中包含的元素为：" << endl;
    for (const auto n : ilst)
        cout << n << " ";
    cout << endl;

    return 0;
}
