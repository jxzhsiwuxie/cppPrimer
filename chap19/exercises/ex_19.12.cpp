//练习 19.12：定义一个成员指针，令其可以指向 Screen 类的 cursor 成员。通过该指针获得 Screen::cursor 成员的值。

#include "Screen.h"


int main(){
    const Screen<100,20>::pos Screen<100,20>::*pCursor;

    return 0;
}

