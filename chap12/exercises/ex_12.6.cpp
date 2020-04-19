//练习 12.6：编写函数，返回一个动态分匹配的 int 的 vector。将此 vector 传递给另一个函数，这个函数读取标准输入，
//将读入的值保存在 vector 元素中。再将 vector 传递给另一个函数，打印读入的值。记得在恰当的时刻 delete vector。

#include <algorithm>
#include <iostream>
#include <iterator>
#include <new>
#include <vector>

using std::cin;
using std::copy;
using std::cout;
using std::endl;
using std::istream_iterator;
using std::ostream_iterator;
using std::vector;

vector<int> *getVector() {
    vector<int> *ptr = new vector<int>();
    return ptr;
}

void readInput(vector<int> *ptr) {
    istream_iterator<int> is_iter(cin), eof;
    while (is_iter != eof)
        ptr->push_back(*is_iter++);
}

void printVector(vector<int> *ptr) {
    ostream_iterator<int> os_iter(cout, " ");
    cout << "vector 中存放的元素为：" << endl;
    copy(ptr->begin(), ptr->end(), os_iter);
    cout << endl;
}

int main() {
    vector<int> *ptr_ivec = getVector();
    cout << "输入几个数字：" << endl;
    readInput(ptr_ivec);
    printVector(ptr_ivec);

    delete ptr_ivec;
    ptr_ivec = nullptr;

    return 0;
}
