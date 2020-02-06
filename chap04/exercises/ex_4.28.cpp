//练习 4.28：编写一段程序，输出每种内置类型所占空间大小。

#include <iostream>

int main() {
    using std::cout;
    using std::endl;

    cout << "当前电脑上 bool 类型所占空间大小为：" << sizeof(bool) << " 字节" <<endl;
    cout << "当前电脑上 char 类型所占空间大小为：" << sizeof(char) << " 字节" <<endl;
    cout << "当前电脑上 short 类型所占空间大小为：" << sizeof(short) << " 字节" <<endl;
    cout << "当前电脑上 int 类型所占空间大小为：" << sizeof(int) << " 字节" <<endl;
    cout << "当前电脑上 long 类型所占空间大小为：" << sizeof(long) << " 字节" <<endl;
    cout << "当前电脑上 long long 类型所占空间大小为：" << sizeof(long long) << " 字节" <<endl;
    cout << "当前电脑上 float 类型所占空间大小为：" << sizeof(float) << " 字节" <<endl;
    cout << "当前电脑上 double 类型所占空间大小为：" << sizeof(double) << " 字节" <<endl;
    cout << "当前电脑上 long double 类型所占空间大小为：" << sizeof(long double) << " 字节" <<endl;

    return 0;
}
