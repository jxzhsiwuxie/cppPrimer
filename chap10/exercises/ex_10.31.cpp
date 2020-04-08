///练习 10.31：修改前一题的程序，使其只打印不重复的元素。你的程序应该使用 unique_copy（参见 10.4.1 节，第 359 页）。


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
using std::unique_copy;

int main() {
    vector<int> ivec;

    cout << "输入一组整数：" << endl;

    istream_iterator<int> in(cin), eof;
    ostream_iterator<int> out(cout, " ");

    while (in != eof)
        ivec.push_back(*in++);

    sort(ivec.begin(), ivec.end());

    cout << "经过排序并去重后：" << endl;
    // copy(ivec.begin(), ivec.end(), out);
    unique_copy(ivec.begin(), ivec.end(), out);

    return 0;
}
