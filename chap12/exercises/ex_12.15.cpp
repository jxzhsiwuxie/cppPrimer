//练习 12.15：重写第一题的程序，使用 lambda（参见 10.3.2 节，第 346 页）代替 end_connection 函数。

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

void f(destination &d) {
    connection c = connect(&d);
    shared_ptr<connection> p(&c, [](connection *p) { cout << "断开连接了……" << endl; });
    //...
}

int main() {
    destination d;
    f(d);
    return 0;
}
