//练习 3.40：编写一段程序，定义两个字符数组并用字符串字面值初始化它们；接着再定义一个字符数组
//存放前面两个数组连接后的结果。使用 strcpy 和 strcat 把前两个数组的内容拷贝到第三个数组中。

#include <iostream>
#include <cstring>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main()
{
    const std::size_t len1 = 12, len2 = 11;
    const char cs1[] = "Hello world!", cs2[] = "Fuck world!";
    char str[len1 + len2 + 1];

    std::strcpy(str, cs1);
    std::strcat(str, cs2);

    cout << "合并之后的字符串为：" << endl;
    cout << str << endl;

    return 0;
}
