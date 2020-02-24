//练习 6.26：编写一个程序，使其接受本节所示的选项：输出传递给 main 函数的实参的内容。

#include <cstddef>
#include <iostream>

using std::cout;
using std::endl;
using std::size_t;

int main(int argc, char* argv[]) {
    cout << "执行程序时输入的参数个数为：" << argc << endl;
    for (size_t i = 0; i < argc; ++i) {
        cout << "第 " << i << " 个实参的内容为：" << argv[i] << endl;
    }

    return 0;
}
