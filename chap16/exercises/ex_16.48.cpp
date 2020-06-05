//练习 16.48：编写你自己版本的 debug_rep 函数。

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

string debug_rep(char *p) {
    return debug_rep(string(p));
}

string debug_rep(const char *p) {
    return debug_rep(string(p));
}

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
