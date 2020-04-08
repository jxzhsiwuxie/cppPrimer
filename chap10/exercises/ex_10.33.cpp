//练习 10.33：编写一个程序，接受三个参数：一个输入文件和两个输出文件的文件名。输入文件保存的应该是整数。
//使用 istream_iterator 读取输入文件。使用 ostream_iterator 将奇数写入第一个输出文件，每个值之后跟一个空格。
//将偶数写入第二个输出文件，每个值都独占一行。

#include <fstream>
#include <iostream>
#include <iterator>

using std::ifstream;
using std::istream_iterator;
using std::ofstream;
using std::ostream_iterator;

int main() {
    ifstream ifs("input.txt");
    ofstream ofs1("output1.txt"), ofs2("output2.txt");

    istream_iterator<int> inIter(ifs), eof;
    ostream_iterator<int> oddIter(ofs1, " "), evenIter(ofs2, "\n");

    while (inIter != eof) {
        if (*inIter % 2)
            *oddIter++ = *inIter;
        else
            *evenIter++ = *inIter;

        ++inIter;
    }

    return 0;
}
