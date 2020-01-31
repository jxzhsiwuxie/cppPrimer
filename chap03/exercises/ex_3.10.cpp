//练习 3.10：编写一段程序，输入一个包含标点符号的字符串，将标点符号去掉后输出剩余的部分。

#include <iostream>
#include <string>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    string str, result;
    cout << "输入一个包含标点符号的字符串：" << endl;
    if (cin >> str)
    {
        if (!str.empty())
        {
            for (auto c : str)
            {
                if (!std::ispunct(c))
                {
                    result += c;
                }
            }
            cout << "去掉标点符号之后的字符串是：" << endl;
            cout << result << endl;
        }
    }

    return 0;
}

