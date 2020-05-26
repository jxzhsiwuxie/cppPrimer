//练习 16.6：你认为接受一个数组实参的标准库函数 begin 和 end 是如何工作的？定义你自己版本的 begin 和 end。

#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>

template <typename T, unsigned n>
T *mBegin(T (&arr)[n]) {
    return arr;
}

template <typename T, unsigned n>
T *mEnd(T (&arr)[n]) {
    return arr + n;
}

int main() {
    std::string strArr[] = {"aaa", "bbb", "ccc"};
    std::ostream_iterator<std::string> osIter(std::cout, " ");
    std::copy(mBegin(strArr), mEnd(strArr), osIter);

    return 0;
}
