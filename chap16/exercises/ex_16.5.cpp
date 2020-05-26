//练习 16.5：为 6.2.4 节（第 195 页）中的 print 函数编写模板版本，它接受一个数组的引用，
//能处理任意大小、任意类型的数组。

#include <iostream>
#include <string>

template <typename T, unsigned n>
void print(T (&arr)[n]) {
    for (const auto &item : arr)
        std::cout << item << std::endl;
}

int main() {
    int intArr[] = {0, 1, 2, 3, 4, 5};
    std::string strArr[] = {"aaa", "bbb", "ccc"};

    print(intArr);
    print(strArr);

    return 0;
}
