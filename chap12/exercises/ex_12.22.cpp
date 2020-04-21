//练习 12.22：为了能让 StrBlobPtr 使用 const StrBlob，你觉得应该如何修改？
//定义一个名为 ConstStrBlobPtr 的类，使其能够指向 const StrBlob。

#include <cstddef>
#include <fstream>
#include <iostream>
#include <string>

#include "ConstStrBlobPtr.h"
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

    ConstStrBlobPtr strb_ptr(strb);
    size_t sz = strb.size();
    for (size_t i = 0; i < sz; ++i) {
        cout << strb_ptr.deref() << endl;
        strb_ptr.incr();
    }

    return 0;
}
