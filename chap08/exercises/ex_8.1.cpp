//练习 8.1：白那些一个函数，接受一个 istream& 参数，返回类型也是 istream&。此函数需从指定流中读取数据，直至遇到文件结束标识符停止。
//它将读取的数据打印在标准输出上。完成这些后，在返回流之前，对流进行复位，使其处于有效状态。

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
