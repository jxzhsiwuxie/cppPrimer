//练习 6.33：编写一个递归函数，输出 vector 对象的内容。

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

void printVector(vector<int>::iterator beg, vector<int>::iterator end) {
    if (beg == end) {
        cout << endl;
        return;
    }

    cout << *beg++ << " ";
    printVector(beg, end);
}


int main() {
    vector<int> ivec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    printVector(ivec.begin(), ivec.end());

    return 0;
}

