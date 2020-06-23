//练习 17.38：扩展上一题中你的程序，将读入的每一个单词打印到它所在的行。

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
