//练习 3.6：编写一段程序，使用范围 for 语句将字符串内的所有字符用 X 代替。

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    string str;
    cout << "输入一行文字：" << endl;
    if (std::getline(cin, str))
    {
        if (str.empty())
            return -1;
        for (auto &c : str)
            c = 'X';
        cout << "修改后的字符串为：" << endl;
        cout << str << endl;
    }

    return 0;
}