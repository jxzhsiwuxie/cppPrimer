//练习 4.37：用命名的强制类型转换改写下列旧式的转换语句。
// int i;    double d;    const string *ps;    char *pc;    void *pv;
// (a) pv = (void*) ps;         (b) i = int(*pc);
// (c) pv = &d;                 (d) pc = (char*) pv;

/*
* (a) pv = static_cast<void *>(const_cast<string *>(ps));       (b) i = static_cast<int>(*pc);
* (c) pv = static_cast<void *>(&d);                             (d) pc = static_cast<char *>(pv);
*/
#include <iostream>
using std::string;

int main() {
    int i;
    double d;
    const string *ps;
    char *pc;
    void *pv;

    // pv = reinterpret_cast<void*>(ps);
    pv = static_cast<void *>(const_cast<string *>(ps));
    // pv = static_cast<void*>(ps);
    // pv = dynamic_cast<void*>(ps);

    i = static_cast<int>(*pc);

    pv = static_cast<void *>(&d);
    pc = static_cast<char *>(pv);

    return 0;
}
