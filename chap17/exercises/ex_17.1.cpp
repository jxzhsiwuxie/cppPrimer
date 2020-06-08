//练习 17.1：定义一个保存三个 int 值的 tuple，并将其值分别初始化为 10、20 和 30。

#include <tuple>

using std::tuple;

int main() {
    tuple<int, int, int> three(10, 20, 30);

    return 0;
}
