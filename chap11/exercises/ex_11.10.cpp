//练习 11.10：可以定义一个 vector<int>::iterator 到 int 的 map 吗？
//list<int>::iterator 到 int 的 map 呢？对于两种情况，如果不能，解释为什么。

/*
* 可以。
* vector<int> 和 list<int> 在 < 操作下都定义了严格弱序，可以作为 map 的关键字。
*/

#include <iostream>
#include <list>
#include <map>
#include <vector>

using std::cout;
using std::endl;
using std::list;
using std::map;
using std::vector;

int main() {
    map<vector<int>, int> ivec_map = {{{1, 2}, 3}, {{2, 3}, 5}};
    map<list<int>, int> ilst_map = {{{1, 2}, 3}, {{2, 3}, 5}};

    cout << "ivec_map 中元素为：" << endl;
    for (const auto &item : ivec_map)
        cout << item.second << " ";
    cout << endl;

    cout << "ilst_map 中元素为：" << endl;
    for (const auto &item : ilst_map)
        cout << item.second << " ";
    cout << endl;

    return 0;
}
