//练习 5.25：修改上一题的程序，使用 try 语句去捕获异常。catch 子句应该为用户输出一条提示信息，
//询问其是否输入新数并重新执行 try 语句块内容。

#include <iostream>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;

int main() {
    int v1, v2;
    char ch = 'y';

    cout << "输入两个整数：";
    while (cin >> v1 >> v2) {
        try {
            if (v2 == 0) {
                throw std::logic_error("除数不能为0。");
            } else {
                cout << v1 << " 除以 " << v2 << " 的结果为：" << static_cast<double>(v1) / v2 << endl;
            }
        } catch (const std::logic_error& e) {
            std::cerr << e.what() << '\n';
            cout << "是否重新输入（y/n）？";

            char c;
            cin >> c;
            if (!c || c == 'n')
                break;
            else
                cout << "输入两个整数：";
        }
    }

    return 0;
}
