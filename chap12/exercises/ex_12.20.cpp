//练习 12.20：编写程序，逐行读入一个输入文件，将内容存入一个 StrBlob 中，用一个 StrBlobPtr 打印出 StrBlob 中的每个元素。

#include <cstddef>
#include <fstream>
#include <iostream>
#include <string>

#include "StrBlobPtr.h"
#include "StrBlob.h"

using std::cout;
using std::endl;
using std::getline;
using std::ifstream;
using std::size_t;
using std::string;

int main() {
    ifstream ifs("strblob.txt");
    string line;
    StrBlob strb;
    while (getline(ifs, line)) {
        strb.push_back(line);
    }

    StrBlobPtr strb_ptr(strb);
    size_t sz = strb.size();
    for (size_t i = 0; i < sz; ++i) {
        cout << strb_ptr.deref() << endl;
        strb_ptr.incr();
    }

    return 0;
}
