//练习 14.35：编写一个类似于 PrintString 的类，令其从 istream 中读取一行输入，
//然后返回一个表示我们所读内容的 string。如果读取失败，返回空 string。

#include "ScanString.h"

int main() {
    ScanString scanStr;

    std::string s = scanStr();

    std::cout << s << std::endl;

    return 0;
}