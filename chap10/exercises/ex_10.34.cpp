//练习 10.34：使用 reverse_iterator 逆序打印一个 vector。

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using std::copy;
using std::cout;
using std::endl;
using std::ostream_iterator;
using std::vector;

int main() {
    vector<int> ivec = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    ostream_iterator<int> out(cout, " ");

    cout << "使用正常顺序打印 vector 中的元素：" << endl;
    copy(ivec.cbegin(), ivec.cend(), out);
    cout << endl;

    cout << "使用正常逆序打印 vector 中的元素：" << endl;
    copy(ivec.crbegin(), ivec.crend(), out);
    cout << endl;

    return 0;
}
