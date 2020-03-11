//练习 9.24：编写程序，分别使用 at、下标运算符、front 和 begin 提取一个 vector 中的第一个元素。在一个空 vector 上测试你的程序。

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main() {
    vector<int> ivec;
    // vector<int> ivec = {1, 2, 3, 4, 5, 6};

    cout << "利用 at 得到 ivec 第一个元素为：" << ivec.at(0) << endl;
    cout << "利用下标运算符得到 ivec 第一个元素为：" << ivec[0] << endl;
    cout << "利用 front 得到 ivec 第一个元素为：" << ivec.front() << endl;
    cout << "利用 begin 得到 ivec 第一个元素为：" << *ivec.begin() << endl;

    return 0;
}
