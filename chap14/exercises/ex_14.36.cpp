//练习 14.36：使用前一个类定义的类读取标准输入，将每一行保存为 vector 的一个元素。

#include <algorithm>
#include <cstddef>
#include <vector>

#include "../samples/PrintString.h"
#include "ScanString.h"

using std::cout;
using std::endl;
using std::for_each;
using std::size_t;
using std::string;
using std::vector;

int main() {
    ScanString scanStr;
    vector<string> svec;

    for (size_t i = 0; i < 3; ++i)
        svec.push_back(scanStr());

    cout << "-------------------------" << endl;
    PrintString printStr(cout, '\n');
    for_each(svec.cbegin(), svec.cend(), printStr);

    return 0;
}
