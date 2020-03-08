//练习 8.2：测试函数，调用参数为 cin。


#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::istream;

istream &readWrite(istream &);

int main() {
    cout << "输入一段文字：" << endl;

    readWrite(cin);

    return 0;
}

istream &readWrite(istream &is) {
    char ch;
    while (!(is >> ch).eof())
        cout << ch;

    is.clear();
    return is;
}
