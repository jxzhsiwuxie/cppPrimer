//练习 17.37：用未格式化版本的 getline 逐行读取一个文件。测试你的程序，给它一个文件，
//既包含空行又包含长度超过你传递给 getline 的字符数组大小的行。

#include <fstream>
#include <iostream>

using std::cout;
using std::endl;
using std::ifstream;

int main() {
    const unsigned size = 12;
    char sink[size];

    ifstream ifs("some.txt");

    ifs.getline(sink, size, EOF);
    cout << sink << endl;

    return 0;
}