//练习 3.21：请使用迭代器重做 3.3.3 节的第一个练习。

#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    vector<int> v1;
    vector<int> v2(10);
    vector<int> v3(10, 42);
    vector<int> v4{10};
    vector<int> v5{10, 42};
    vector<string> v6{10};
    vector<string> v7{10, "hi"};

    int tmp;

    cout << "v1 的容量是 " << (tmp = v1.size()) << endl;
    if (tmp > 0)
    {
        cout << "v1 内包含的元素为：" << endl;
        for (auto it = v1.cbegin(); it != v1.cend(); ++it)
            cout << *it << " ";
        cout << endl;
    }
    cout << endl;

    cout << "v2 的容量是 " << (tmp = v2.size()) << endl;
    if (tmp > 0)
    {
        cout << "v2 内包含的元素为：" << endl;
        for (auto it = v2.cbegin(); it != v2.cend(); ++it)
            cout << *it << " ";
        cout << endl;
    }
    cout << endl;

    cout << "v3 的容量是 " << (tmp = v3.size()) << endl;
    if (tmp > 0)
    {
        cout << "v3 内包含的元素为：" << endl;
        for (auto it = v3.cbegin(); it != v3.cend(); ++it)
            cout << *it << " ";
        cout << endl;
    }
    cout << endl;

    cout << "v4 的容量是 " << (tmp = v4.size()) << endl;
    if (tmp > 0)
    {
        cout << "v4 内包含的元素为：" << endl;
        for (auto it = v4.cbegin(); it != v4.cend(); ++it)
            cout << *it << " ";
        cout << endl;
    }
    cout << endl;

    cout << "v5 的容量是 " << (tmp = v5.size()) << endl;
    if (tmp > 0)
    {
        cout << "v5 内包含的元素为：" << endl;
        for (auto it = v5.cbegin(); it != v5.cend(); ++it)
            cout << *it << " ";
        cout << endl;
    }
    cout << endl;

    cout << "v6 的容量是 " << (tmp = v6.size()) << endl;
    if (tmp > 0)
    {
        cout << "v6 内包含的元素为：" << endl;
        for (auto it = v6.cbegin(); it != v6.cend(); ++it)
            cout << *it << " ";
        cout << endl;
    }
    cout << endl;

    cout << "v7 的容量是 " << (tmp = v7.size()) << endl;
    if (tmp > 0)
    {
        cout << "v7 内包含的元素为：" << endl;
        for (auto it = v7.cbegin(); it != v7.cend(); ++it)
            cout << *it << " ";
        cout << endl;
    }
    cout << endl;

    return 0;
}
