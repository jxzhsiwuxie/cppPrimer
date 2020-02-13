//练习 5.24：修改你的程序，使得当第二个数是 0 时抛出异常。先不要设定 catch 子句，
//运行程序并真的为除数输入 0，看看会发生什么？

#include <iostream>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;

int main() {
    int v1, v2;

    cout << "输入两个整数：";
    if (cin >> v1 >> v2) {
        if (v2 == 0) {
            throw std::logic_error("除数不能为0。");
        } else {
            cout << v1 << " 除以 " << v2 << " 的结果为：" << static_cast<double>(v1) / v2 << endl;
        }
    }

    return 0;
}

/*
* 给除数输入 0，程序中断，控制台报出设定好的错误。
*/
