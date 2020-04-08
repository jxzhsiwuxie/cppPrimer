//练习 10.29：编写程序，使用流迭代器读取一个文本文件，存入一个 vector 中的 string 里。

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using std::copy;
using std::cout;
using std::endl;
using std::ifstream;
using std::istream_iterator;
using std::ostream_iterator;
using std::string;
using std::vector;

int main() {
    vector<string> svec;

    ifstream ifs("10.29");
    istream_iterator<string> lineIter(ifs), eof;
    ostream_iterator<string> out(cout);

    while (lineIter != eof)
        svec.push_back(*lineIter++);

    // for (const auto &s : svec)
    //     cout << s << endl;

    copy(svec.begin(), svec.end(), out);

    return 0;
}
