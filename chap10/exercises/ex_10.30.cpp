//练习 10.30：使用流迭代器、sort 和 copy 从标准输入读取一个整数序列，将其排序，并将结果写到标准输出。

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::istream_iterator;
using std::ostream_iterator;
using std::vector;

using std::copy;
using std::sort;

int main() {
    vector<int> ivec;

    cout << "输入一组整数：" << endl;

    istream_iterator<int> in(cin), eof;
    ostream_iterator<int> out(cout, " ");

    while (in != eof)
        ivec.push_back(*in++);

    sort(ivec.begin(), ivec.end());

    cout << "经过排序后：" << endl;
    copy(ivec.begin(), ivec.end(), out);

    return 0;
}
