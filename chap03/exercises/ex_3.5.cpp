//练习 3.5：编写一段程序从标准输入中读入多个字符串并将它们拼接在一起，输出连接成的大字符串。
//然后修改上述程序，用空格把输入的多个字符串分隔开来。

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    string total1, total2, tmp;
    cout << "请输入多个字符串：" << endl;

    while (cin >> tmp)
    {
        total1 += tmp;
        total2 += tmp + " ";
    }

    cout << "直接拼接起来的字符串是：" << endl;
    cout << total1 << endl;

    cout << "用空格分隔开来来的字符串是：" << endl;
    cout << total2 << endl;

    return 0;
}