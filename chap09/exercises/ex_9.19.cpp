//练习 9.19：重写上提程序，使用 list 代替 deque。列出程序需要做出哪些修改。

#include <iostream>
#include <list>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::list;
using std::string;

int main() {
    string str;
    list<string> strList;
    cout << "输入一句话：" << endl;

    while (cin >> str)
        strList.push_back(str);

    cout << "输入的句子为：" << endl;

    auto cbeg = strList.cbegin(), cend = strList.cend();
    while (cbeg != cend)
        cout << *cbeg++ << " ";
    cout << endl;

    return 0;
}
