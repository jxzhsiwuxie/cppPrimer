//练习 9.18：编写程序，从标准输入读取 string 序列，存入一个 deque 中。编写一个循环，用迭代器打印 deque 中元素。

#include <deque>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::deque;
using std::endl;
using std::string;

int main() {
    string str;
    deque<string> strDeque;
    cout << "输入一句话：" << endl;

    while (cin >> str)
        strDeque.push_back(str);

    cout << "输入的句子为：" << endl;

    auto cbeg = strDeque.cbegin(), cend = strDeque.cend();
    while (cbeg != cend)
        cout << *cbeg++ << " ";
    cout << endl;

    return 0;
}
