//练习 6.25：编写一个 main 函数，令其接受两个实参。把实参的内容连接成一个 string 对象并输出出来。

#include <cstddef>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::size_t;
using std::string;

int main(int argc, char* argv[]) {
    string argStr;

    cout << "执行程序时输入的参数个数为：" << argc << endl;
    for (size_t i = 0; i < argc; ++i) {
        argStr += argv[i];
    }

    cout << "所有实参连接起来为：" << endl;
    cout << argStr << endl;

    return 0;
}
