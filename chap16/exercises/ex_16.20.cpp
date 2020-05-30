//练习 16.20：重写上一题的函数，利用 begin 和 end 返回的迭代器来控制循环。

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

template <typename T>
void printContainer(T &container) {
    typename T::iterator beg, end;
    for (beg = container.begin(); beg != container.end(); ++beg)
        cout << *beg << " ";
    cout << endl;
}

int main() {
    string str = "dadsdasdsadda";
    vector<int> ivec = {1, 2, 3, 4, 5, 6, 7, 8};

    printContainer(str);
    printContainer(ivec);

    return 0;
}
