//练习 12.24：编写一个程序，从标准输入读取一个字符串，存入一个动态分配的字符数组中。
//描述你的程序如何处理变长输入。测试你的程序，输入一个超出你分配的数组长度的字符串。

#include <cstddef>
#include <cstring>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::size_t;
using std::string;

int main() {
    const size_t len = 100;
    string line;
    char *str = new char[len]();
    

    cout << "输入一个字符串：" << endl;
    if (getline(cin, line)) {
        for (size_t i = 0; i < line.size() && i < len; ++i)
            str[i] = line.at(i);
    }

    cout << "字符数组中存的值为：" << endl;
    for (size_t i = 0; i < len; ++i)
        cout << str[i] << " ";
    cout << endl;

    return 0;
}