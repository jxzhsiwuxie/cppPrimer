//练习 3.8：分别使用 while 循环和传统 for 循环重写第一题的程序，
//你觉得哪种形式更好呢？为什么？

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

//使用 while 循环
// int main()
// {
//     string str;
//     cout << "输入一行文字：" << endl;
//     if (std::getline(cin, str))
//     {
//         if (str.empty())
//             return -1;

//         string::size_type idx = 0;
//         while (idx < str.size())
//             str[idx++] = 'X';

//         cout << "修改后的字符串为：" << endl;
//         cout << str << endl;
//     }

//     return 0;
// }

//使用传统 for 循环
int main()
{
    string str;
    cout << "输入一行文字：" << endl;
    if (std::getline(cin, str))
    {
        if (str.empty())
            return -1;

        for (string::size_type idx = 0; idx < str.size(); ++idx)
            str[idx] = 'X';

        cout << "修改后的字符串为：" << endl;
        cout << str << endl;
    }

    return 0;
}


/*
* 显然是使用范围 for 循环更好。
* 一方面更加的方便，另一方面以为不需要通过索引来访问字符串内的元素所以更加安全。
*/