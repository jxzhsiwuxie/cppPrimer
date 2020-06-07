//练习 116.65：在 16.3 节（第 617 页）我们定义了两个重载的 debug_rep 版本，一个接受 const char* 参数，另一个接受 char* 参数。
//将这两个函数重写为特例化版本。

#include <iostream>
#include <sstream>
#include <string>

using std::cout;
using std::endl;
using std::ostringstream;
using std::string;

template <typename T>
string debug_rep(const T &t);

template <typename T>
string debug_rep(T *p);

string debug_rep(const string &);

string debug_rep(const string &s) {
    return '"' + s + '"';
}

template <typename T>
string debug_rep(const T &t) {
    ostringstream ret;
    ret << t;
    return ret.str();
}

template <typename T>
string debug_rep(T *p) {
    ostringstream ret;
    ret << "pointer: " << p;
    if (p)
        ret << debug_rep(*p);
    else
        ret << "null pointer";
    return ret.str();
}

template <>
string debug_rep(char *p) {
    return debug_rep(string(p));
}

template <>
string debug_rep(const char *p) {
    return debug_rep(string(p));
}