//练习 16.39：对 16.1.1 节（第 578 页）中的原始版本的 compare 函数，使用一个显式模板实参，使得可以向函数传递两个字符串字面常量。

#include <string>
using std::string;

template <typename T>
int compare(const T &v1, const T &v2) {
    if (v1 < v2)
        return -1;
    if (v2 < v1)
        return 1;
    return 0;
}

int main() {
    compare<string>("dadsdad", "ewrfewrwrf");

    return 0;
}