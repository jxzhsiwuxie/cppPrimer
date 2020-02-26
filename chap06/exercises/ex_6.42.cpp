//练习 6.42：给程序 make_plural 函数（参见 6.3.2 节）第二个形参赋予默认实参 's'，
//利用新版本的函数输出单词 success 和 failure 的单数和复数形式。

#include <cstddef>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::size_t;
using std::string;

string make_plural(size_t ctr, const string &word, const string &ending = "s") {
    return (ctr > 1) ? word + ending : word;
}

int main() {
    cout << "success的单数形式：" << make_plural(1, "success") << endl;
    cout << "success的复数形式：" << make_plural(2, "success", "es") << endl;

    cout << "failure 的单数形式：" << make_plural(1, "failure") << endl;
    cout << "failure 的复数形式：" << make_plural(2, "failure") << endl;

    return 0;
}
