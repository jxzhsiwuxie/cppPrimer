//练习 13.36：设计并实现对应的 Folder 类。此类应该保存一个指向 Folder 中包含的 Messag 的 set。

#include <iostream>

#include "Message_Folder.h"

using std::cout;
using std::endl;

int main() {
    Folder folder1;

    Message msg1("这是第一条消息");
    msg1.save(folder1);

    Folder folder2(folder1);
    Message msg2("这是第二条消息");
    msg2.save(folder2);

    Message msg11(msg1);
    Message msg21;
    msg21 = msg2;

    Folder folder11;
    folder11 = folder1;
    folder11.addMsg(&msg11);
    folder11.addMsg(&msg21);

    folder11.remMsg(&msg1);

    msg1.print();
    cout << "----------------------" << endl;
    msg2.print();
    cout << "----------------------" << endl;
    msg11.print();
    cout << "----------------------" << endl;
    msg21.print();
    cout << "----------------------" << endl;

    folder1.print();
    cout << "----------------------" << endl;
    folder2.print();
    cout << "----------------------" << endl;
    folder11.print();
    cout << "----------------------" << endl;

    return 0;
}
