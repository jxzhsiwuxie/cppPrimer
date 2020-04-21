//练习 12.14：比起那些你自己版本的用 shared_ptr 管理 connection 的函数。

#include <iostream>
#include <memory>

using std::cout;
using std::endl;
using std::shared_ptr;

struct destination {};
struct connection {};

connection connect(destination *) {
    cout << "创建了连接……" << endl;
    return connection();
}
void disconnect(connection) { cout << "断开连接了……" << endl; }

void end_connection(connection *p) { disconnect(*p); }

void f(destination &d) {
    connection c = connect(&d);
    shared_ptr<connection> p(&c, end_connection);
    //...
}

int main() {
    destination d;
    f(d);
    return 0;
}
