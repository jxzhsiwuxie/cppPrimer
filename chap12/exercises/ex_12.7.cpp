//练习 12.7：重做上一题，这次使用 shared_ptr 而不是内置指针。

#include <algorithm>
#include <iostream>
#include <iterator>
#include <memory>
#include <new>
#include <vector>

using std::cin;
using std::copy;
using std::cout;
using std::endl;
using std::istream_iterator;
using std::ostream_iterator;
using std::shared_ptr;
using std::vector;

using std::make_shared;

shared_ptr<vector<int>> getVector() {
    auto ptr = make_shared<vector<int>>();
    return ptr;
}

shared_ptr<vector<int>> readInput(shared_ptr<vector<int>> ptr) {
    istream_iterator<int> is_iter(cin), eof;
    while (is_iter != eof)
        ptr->push_back(*is_iter++);
    return ptr;
}

shared_ptr<vector<int>> printVector(shared_ptr<vector<int>> ptr) {
    ostream_iterator<int> os_iter(cout, " ");
    cout << "vector 中存放的元素为：" << endl;
    copy(ptr->begin(), ptr->end(), os_iter);
    cout << endl;
    return ptr;
}

int main() {
    shared_ptr<vector<int>> ptr_ivec = getVector();

    cout << "输入几个数字：" << endl;
    cout << ptr_ivec.use_count() << endl;

    ptr_ivec = printVector(ptr_ivec);

    return 0;
}
