//练习 10.8：本节提到过，标准库算法不会改变它们所操作的容器的大小。为什么使用 back_inserter 不会使这种断言失效？

/*
* back_inserter 之所以能改变所操作的容器的大小并不是其本身的功能，而是它调用了容器自身的 push_back 方法来向容器中插入元素的。
* 所以如果容器本身不支持 push_back 的功能，使用 back_inserter 也是无法改变容器大小的。
*/

#include <forward_list>
#include <iostream>
#include <iterator>

using std::back_inserter;
using std::front_inserter;
using std::cin;
using std::cout;
using std::endl;
using std::fill_n;
using std::forward_list;

int main() {
    forward_list<int> flst;
    // fill_n(back_inserter(flst), 10, 1);
    fill_n(front_inserter(flst), 10, 1);

    cout << "flst 中元素为：" << endl;
    for (const auto n : flst)
        cout << n << " ";
    cout << endl;

    return 0;
}
