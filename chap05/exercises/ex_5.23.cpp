//练习 5.23：编写一段程序，从标准输入读取两个整数，输出第一个数除以第二个数的结果。

#include <iostream>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;

int main() {
    int v1, v2;

    cout << "输入两个整数：";
    if (cin >> v1 >> v2) {
        try {
            if (v2 == 0) {
                throw std::logic_error("除数不能为0。");
            } else {
                cout << v1 << " 除以 " << v2 << " 的结果为：" << static_cast<double>(v1) / v2 << endl;
            }
        } catch (const std::logic_error& e) {
            std::cerr << e.what() << '\n';
        }
    }

    return 0;
}
