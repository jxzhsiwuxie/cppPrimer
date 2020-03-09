//练习 9.5：重写上一题的函数，返回一个迭代器指向找到的元素。注意，程序必须处理未找到指定值的情况。

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

vector<int>::const_iterator &findNum(vector<int>::const_iterator &, vector<int>::const_iterator &, int);

int main() {
    vector<int> ivec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = -1;

    cout << "输入一个整数：";
    if (cin >> n) {
        vector<int>::const_iterator beg = ivec.cbegin(), end = ivec.cend();
        auto res = findNum(beg, end, n);
        // bool res = findNum(ivec.cbegin(), ivec.cend(), n);

        cout << (res == end ? "没有找到了数字 " : "找到了数字 ") << n << endl;
    }

    return 0;
}

vector<int>::const_iterator &findNum(vector<int>::const_iterator &beg, vector<int>::const_iterator &end, int n) {
    while (beg != end) {
        if (*beg == n)
            break;
        else
            ++beg;
    }
    return beg;
}
