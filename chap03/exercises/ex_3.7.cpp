//练习 3.7：就上一题完成的程序而言，如果将循环变量的类型设为 char 将会发生什么？
//先估计一下结果然后实际编程进行验证。

/*
* 如果将循环变量设为 char，则循环体内修改的只是临时变量 c 的值，字符串本身并不会受到影响。
*/

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
        for (auto c : str)
            c = 'X';
        cout << "修改后的字符串为：" << endl;
        cout << str << endl;
    }

    return 0;
}