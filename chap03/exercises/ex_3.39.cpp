//练习 3.39：编写一段程序，比较两个 string 对象。再编写一段程序，比较两个 C 风格字符串的内容。

#include <iostream>
#include <cstring>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main()
{
    const string s1 = "Hello world!", s2 = "Fuck world!";
    const char *cs1 = "Hello world!", *cs2 = "Fuck world!";

    cout << "string 字符串 " << (s1 > s2 ? "s1" : "s2") << " 比较大" << endl;
    cout << "C 风格字符串 " << (std::strcmp(cs1, cs2) > 0 ? "cs1" : "cs2") << " 比较大" << endl;

    return 0;
}
