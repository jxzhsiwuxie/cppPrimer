//练习 8.9：使用你为 8.1.2 （第 281 页）节第一个练习编写的函数打印一个 istringstream 对象的内容。

#include <iostream>
#include <sstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::istream;
using std::istringstream;
using std::string;

istream &readWrite(istream &);

int main() {
    cout << "输入一段文字：" << endl;
    string str;
    getline(cin, str);

    istringstream iss(str);

    readWrite(iss);

    return 0;
}

istream &readWrite(istream &is) {
    char ch;
    while (!(is >> ch).eof())
        cout << ch;

    is.clear();
    return is;
}
