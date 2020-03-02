//练习 7.27：给你自己的 Screen 类添加 move、set 和 display 函数，通过执行下面的代码验证你的类是否正确。
// Screen myScreen(5, 5, 'X');
// myScreen.move(4, 0).set('#').display(cout);
// cout << "\n";
// myScreen.display(cout);
// cout << "\n";

#include <iostream>
#include "Screen.h"

using std::cout;

int main() {
    Screen myScreen(5, 5, 'X');
    myScreen.move(4, 0).set('#').display(cout);
    cout << "\n";
    myScreen.display(cout);
    cout << "\n";

    return 0;
}
