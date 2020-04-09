//练习 10.35：使用普通迭代器逆序打印一个 vector。

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

    for (auto it = ivec.cend() - 1; it != ivec.cbegin() - 1; --it)
        cout << *it << " ";
    cout << endl;

    return 0;
}
