//练习 7.32：定义你自己的 Screen 和 Window_mgr，其中 clear 是 Window_mgr 的成员，是 Screen 的友元。

#include <iostream>
#include "Screen.h"

using std::cout;
using std::endl;

int main() {
    Screen myScreen(5, 5, 'X');
    myScreen.move(4, 0).set('#').display(cout);
    cout << endl;
    myScreen.display(cout);
    cout << endl;

    Window_mgr wm;
    wm.clear(0);

    return 0;
}
