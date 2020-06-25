//练习 18.5：修改下面的 main 函数，使其能捕获图 18.1（第 693 页）所示的任何异常类型。
// int main() {
// 使用 C++ 标准库
//}
//处理代码应该首先打印异常相关的错误信息，然后调用 abort （定义在 cstdlib 头文件中）终止 main 函数。

#include <cstdlib>
#include <iostream>
#include <stdexcept>

using std::abort;
using std::cerr;
using std::endl;
using std::exception;

int main() {
    try {
        // 使用 C++ 标准库
    } catch (const exception e) {
        cerr << e.what() << endl;
        abort();
    }
}
