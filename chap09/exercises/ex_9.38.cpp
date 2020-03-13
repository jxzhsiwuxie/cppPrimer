//练习 9.38：编写程序，探究在你的标准库实现中， vector 是如何增长的。

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main() {
    vector<int> ivec;
    cout << "初始时 vecotor 的 size = " << ivec.size() << "，capacity = " << ivec.capacity() << endl;

    for (int i = 0; i < 10; ++i) {
        ivec.push_back(i);
        cout << "当 vecotor 的 size = " << ivec.size() << "时，capacity = " << ivec.capacity() << endl;
    }

    return 0;
}
