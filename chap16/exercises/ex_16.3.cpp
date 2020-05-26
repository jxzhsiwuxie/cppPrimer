//练习 16.3：对两个 Sales_data 调用你的 compare 函数，观察编译器在实例化过程中如何处理错误。

#include <iostream>

#include "Sales_data.h"

using std::cout;
using std::endl;

template <typename T>
int compare(const T &v1, const T &v2) {
    if (v1 < v2)
        return -1;
    if (v2 < v1)
        return 1;
    return 0;
}

int main() {
    Sales_data data1, data2;

    cout << compare<Sales_data>(data1, data2) << endl;

    return 0;
}

/*
.\Sales_data.h: In member function 'Sales_data& Sales_data::operator=(const string&)':
.\Sales_data.h:123:1: warning: no return statement in function returning non-void [-Wreturn-type]
 }
 ^
.\ex_16.3.cpp: In instantiation of 'int compare(const T&, const T&) [with T = Sales_data]':
.\ex_16.3.cpp:22:45:   required from here
.\ex_16.3.cpp:12:12: error: no match for 'operator<' (operand types are 'const Sales_data' and 'const Sales_data')
     if (v1 < v2)
         ~~~^~~~
.\ex_16.3.cpp:12:12: note: candidate: 'operator<(double, double)' <built-in>
.\ex_16.3.cpp:12:12: note:   no known conversion for argument 2 from 'const Sales_data' to 'double'
.\ex_16.3.cpp:14:12: error: no match for 'operator<' (operand types are 'const Sales_data' and 'const Sales_data')
     if (v2 < v1)
         ~~~^~~~
.\ex_16.3.cpp:14:12: note: candidate: 'operator<(double, double)' <built-in>
.\ex_16.3.cpp:14:12: note:   no known conversion for argument 2 from 'const Sales_data' to 'double'
*/