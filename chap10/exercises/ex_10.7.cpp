//练习 10.7：下面程序是否有错误？如果有，请改正。
//(a) vector<int> vec; list<int> lst; int i;
// while(cin >> i)
//     lst.push_back(i);
// copy(lst.cbegin(), lst.cend(), vec.begin());

//(b) vector<int> vec;
// vec.reserve(10);
// fill_n(vec.begin(), 10, 0);

/*
* (a) 有错误，vec 为空，不能直接使用 vec.begin() 作为 copy 算法的第三个参数，否则会发生未知错误。
* 可以将第三个参数换为 back_inserter(vec)。
* (b) 有错误，虽然 reserve 能够控制 vector 预先分配的空间的大小，但是里面元素个数仍然是0，所以 vec 仍然是空的。
* 而 fill_n 算法并不会改变 vec 的大小，所以实际上无法将数据填充进 vec 中。
* 同样可以将 vec.begin() 换为 back_inserter(vec)。
*/

#include <iostream>
#include <iterator>
#include <list>
#include <vector>

using std::back_inserter;
using std::cin;
using std::cout;
using std::endl;
using std::fill_n;
using std::list;
using std::vector;

void test1() {
    vector<int> vec;
    list<int> lst;
    int i;
    while (cin >> i)
        lst.push_back(i);

    cout << "lst 中元素为：" << endl;
    for (const auto n : lst)
        cout << n << " ";
    cout << endl;

    // copy(lst.cbegin(), lst.cend(), vec.begin());
    copy(lst.cbegin(), lst.cend(), back_inserter(vec));
    cout << "vec 中元素为：" << endl;
    for (const auto n : vec)
        cout << n << " ";
    cout << endl;
}

void test2() {
    vector<int> vec;
    vec.reserve(10);
    // fill_n(vec.begin(), 10, 0);
    fill_n(back_inserter(vec), 10, 0);

    cout << "vec 中元素为：" << endl;
    for (const auto n : vec)
        cout << n << " ";
    cout << endl;
}

int main() {
    test1();

    test2();

    return 0;
}
