//练习 10.21：编写一个 lambda，捕获一个局部 int 变量，并递减变量值，直至它变为 0。
//一旦变量为 0，再调用 lambda 应该不再递减变量。lambda 应该返回一个 bool 值，指出捕获的变量是否为 0。

#include <iostream>

using std::cout;
using std::endl;

int main() {
    int i = 10;

    auto fn = [&i]() -> bool {
        if (i) {
            --i;
            return false;
        } else {
            return true;
        }
    };

    while (!fn()) {
        cout << "当前 i 的值为：" << i << endl;
    }

    return 0;
}
