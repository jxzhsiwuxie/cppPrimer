//练习 9.4：编写程序，接受一对指向 vector<int> 的爹大气和一个 int 值。在两个迭代器指定的范围中查找给定的值，返回一个布尔值来指示是否找到。

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

bool findNum(vector<int>::const_iterator &, vector<int>::const_iterator &, int);

int main() {
    vector<int> ivec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = -1;

    cout << "输入一个整数：";
    if (cin >> n) {
        vector<int>::const_iterator beg = ivec.cbegin(), end = ivec.cend();
        bool res = findNum(beg, end, n);
        // bool res = findNum(ivec.cbegin(), ivec.cend(), n);

        cout << (res ? "找到了数字 " : "没有找到数字 ") << n << endl;
    }

    return 0;
}

bool findNum(vector<int>::const_iterator &beg, vector<int>::const_iterator &end, int n) {
    while (beg != end) {
        if (*beg++ == n)
            return true;
    }
    return false;
}
