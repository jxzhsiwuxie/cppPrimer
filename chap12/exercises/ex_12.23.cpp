//练习 12.23：编写一个程序，连接两个字符串字面值常量，将结果保存在一个动态分配的 char 数组中。
//重写这个程序，连接两个标准库 string 对象。

#include <cstddef>
#include <cstring>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::size_t;
using std::string;

const char *combine2Str(const char *str1, const char *str2) {
    size_t len1 = std::strlen(str1), len2 = std::strlen(str2);
    size_t len = len1 + len2;

    char *str = new char[len + 1];
    std::strcpy(str, str1);
    for (size_t i = len1; i < len; ++i)
        str[i] = str2[i - len1];
    str[len] = '\0';

    return str;
}

const char *combine2String(const string &s1, const string &s2) {
    size_t len1 = s1.size(), len2 = s2.size();
    size_t len = len1 + len2;

    char *str = new char[len + 1];
    for (size_t i = 0; i < len1; ++i)
        str[i] = s1.at(i);

    for (size_t i = len1; i < len; ++i)
        str[i] = s2.at(i - len1);
    str[len] = '\0';

    return str;
}

int main() {
    const char *str1 = "abcdefghi8", *str2 = "cdefghi";
    cout << "待拼接的两个字符串常量分别是：\"" << str1 << "\"  和 \"" << str2 << "\"。" << endl;
    const char *str = combine2Str(str1, str2);
    cout << "拼接后得到的字符串常量为：" << str << endl;

    const string s1 = "abcdefghi8", s2 = "cdefghi";
    cout << "待拼接的两个字符串分别是：\"" << s1 << "\"  和 \"" << s2 << "\"。" << endl;
    const char *s = combine2String(s1, s2);
    cout << "拼接后得到的字符串常量为：" << s << endl;

    return 0;
}
