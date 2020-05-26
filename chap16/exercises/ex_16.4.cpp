//练习 16.4：编写行为类似标准库 find 算法的模板。函数需要两个模板类型参数，一个表示函数的迭代器参数，
//另一个表示值的类型。使用你的函数在一个 vector<int> 和一个 list<string> 中查找给定值。

#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::find;
using std::list;
using std::string;
using std::vector;

template <typename IT, typename T>
IT mFind(IT iter1,  const IT &iter2, const T &val) {
    while (iter1 != iter2) {
        if (*iter1 == val)
            return iter1;
        ++iter1;
    }
    return iter1;
}

int main() {
    vector<int> ivec = {1, 23, 34, 555, 4542, 3, 2, 25};
    list<string> slist = {"aaa", "ccc", "bbb", "eee"};

    auto it0 = find(ivec.begin(), ivec.end(), 2);
    cout << "第 " << (it0 - ivec.begin()) << endl;

    auto it1 = find(slist.begin(), slist.end(), "ccc");
    if (it1 != slist.end())
        cout << "找到了" << endl;
    else
        cout << "没找到" << endl;

    cout << "-------------" << endl;

    auto it2 = mFind<vector<int>::iterator, int>(ivec.begin(), ivec.end(), 2);
    cout << "第 " << (it2 - ivec.begin()) << endl;

    auto it3 = mFind(slist.begin(), slist.end(), "ccc");
    if (it3 != slist.end())
        cout << "找到了" << endl;
    else
        cout << "没找到" << endl;

    return 0;
}
