//练习 9.31：第 316 页中删除偶数值元素并复制奇数值元素的程序不能用于 list 或 forward_list。为什么？修改程序，使之也能用于这些类型。

/*
* list 的迭代器不支持 += n 的操作；forward_list 不支持 insert 和 erase 函数。
*/

#include <forward_list>
#include <iostream>
#include <list>
#include <vector>

using std::cout;
using std::endl;
using std::forward_list;
using std::list;
using std::vector;

void someFunc(vector<int> &);
void someFunc(list<int> &);
void someFunc(forward_list<int> &);

int main() {
    vector<int> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    list<int> lst = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    forward_list<int> flst = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    someFunc(vi);
    cout << "执行之后 vector 中元素为：" << endl;
    for (auto n : vi)
        cout << n << " ";
    cout << endl;

    someFunc(lst);
    cout << "执行之后 list 中元素为：" << endl;
    for (auto n : lst)
        cout << n << " ";
    cout << endl;

    someFunc(flst);
    cout << "执行之后 forward_list 中元素为：" << endl;
    for (auto n : flst)
        cout << n << " ";
    cout << endl;

    return 0;
}

void someFunc(vector<int> &ivec) {
    auto iter = ivec.begin();
    while (iter != ivec.end()) {
        if (*iter % 2) {
            iter = ivec.insert(iter, *iter);
            iter += 2;
        } else
            iter = ivec.erase(iter);
    }
}

void someFunc(list<int> &ilst) {
    auto iter = ilst.begin();
    while (iter != ilst.end()) {
        if (*iter % 2) {
            iter = ilst.insert(iter, *iter);
            ++iter;
            ++iter;
        } else
            iter = ilst.erase(iter);
    }
}

void someFunc(forward_list<int> &iflst) {
    auto iter = iflst.begin(), prev = iflst.before_begin();
    while (iter != iflst.end()) {
        if (*iter % 2) {
            iter = iflst.insert_after(iter, *iter);
            prev = iter;
            ++iter;
        } else {
            iter = iflst.erase_after(prev);
        }
    }
}