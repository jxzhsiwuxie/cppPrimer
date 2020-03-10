//练习 9.21：如果我们将 308 页中使用 insert 返回值将元素添加到 list 中的循环程序改写为将元素插入到 vector 中，分析循环将如何工作。

#include <iostream>
#include <list>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::list;
using std::string;
using std::vector;

// list<string> lst;
// auto iter = lst.begin();
// string word;
// while (cin >> word)
//     iter = lst.insert(iter, word);

int main() {
    vector<string> vec;
    auto iter = vec.begin();
    string word;

    while (cin >> word)
        iter = vec.insert(iter, word);

    return 0;
}


/*
* 相当于对 vector 做了 push_front 的操作。
*/
