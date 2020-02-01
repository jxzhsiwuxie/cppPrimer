//练习 3.16：编写一段程序，把练习 3.13 中 vector 对象的容量和具体内容输出出来。
//检查尼之前的回答是否正确，如果不对，回过头重新学习 3.3.1 节知道弄明白错在何处为止。

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
        for (auto val : v1)
            cout << val << " ";
        cout << endl;
    }
    cout << endl;

    cout << "v2 的容量是 " << (tmp = v2.size()) << endl;
    if (tmp > 0)
    {
        cout << "v2 内包含的元素为：" << endl;
        for (auto val : v2)
            cout << val << " ";
        cout << endl;
    }
    cout << endl;

    cout << "v3 的容量是 " << (tmp = v3.size()) << endl;
    if (tmp > 0)
    {
        cout << "v3 内包含的元素为：" << endl;
        for (auto val : v3)
            cout << val << " ";
        cout << endl;
    }
    cout << endl;

    cout << "v4 的容量是 " << (tmp = v4.size()) << endl;
    if (tmp > 0)
    {
        cout << "v4 内包含的元素为：" << endl;
        for (auto val : v4)
            cout << val << " ";
        cout << endl;
    }
    cout << endl;

    cout << "v5 的容量是 " << (tmp = v5.size()) << endl;
    if (tmp > 0)
    {
        cout << "v5 内包含的元素为：" << endl;
        for (auto val : v5)
            cout << val << " ";
        cout << endl;
    }
    cout << endl;

    cout << "v6 的容量是 " << (tmp = v6.size()) << endl;
    if (tmp > 0)
    {
        cout << "v6 内包含的元素为：" << endl;
        for (auto val : v6)
            cout << val << " ";
        cout << endl;
    }
    cout << endl;

    cout << "v7 的容量是 " << (tmp = v7.size()) << endl;
    if (tmp > 0)
    {
        cout << "v7 内包含的元素为：" << endl;
        for (auto val : v7)
            cout << val << " ";
        cout << endl;
    }
    cout << endl;

    return 0;
}
