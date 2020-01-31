//练习 3.4：编写一段程序读取两个字符串，比较其是否相等并输出结果。如果不相等，输出较大的那个字符串。
//改写上述程序，比较两个字符串是否等长，如果不等长，输出长度较大的那个字符串。

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

//比较两个字符串是否相等
// int main()
// {
//     string s1, s2;
//     cout << "输入两个字符串，可以在一行：" << endl;
//     cin >> s1 >> s2;

//     if (s1 == s2)
//         cout << "两个字符串相等" << endl;
//     else if (s1 > s2)
//         cout << "两个字符串不相等并且较大的那个是：" << s1 << endl;
//     else
//         cout << "两个字符串不相等并且较大的那个是：" << s2 << endl;

//     return 0;
// }


//比较两个字符串长度是否相等
int main()
{
    string s1, s2;
    cout << "输入两个字符串，可以在一行：" << endl;
    cin >> s1 >> s2;

    if (s1.size() == s2.size())
        cout << "两个字符串长度相等" << endl;
    else if (s1.size() > s2.size())
        cout << "两个字符串长度不相等并且较大的那个是：" << s1 << endl;
    else
        cout << "两个字符串长度不相等并且较大的那个是：" << s2.size() << endl;

    return 0;
}