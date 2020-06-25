//练习 18.6：已知下面的异常类型和 catch 语句，书写一个 throw 表达式使其创建的异常对象能被这些 catch 语句捕获。
// (a) class exceptionType { };
//     catch(exceptionType *pet) { }
// (b) catch(...) { }
// (c) typedef int EXCPTYPE;
//     catch(EXCPTYPE) { }

#include <iostream>

using std::cerr;
using std::endl;

class exceptionType {};

int main() {
    try {
        throw new exceptionType();
    } catch (exceptionType *pet) {
        cerr << "1" << endl;
        //...
    }

    try {
        throw new exceptionType();
    } catch (...) {
        cerr << "2" << endl;
        //...
    }

    typedef int EXCPTYPE;
    try {
        EXCPTYPE i;
        throw i;
    } catch (EXCPTYPE) {
        cerr << "3" << endl;
        //...
    }

    return 0;
}
