//练习 6.30：编译第 200 页的 str_subrange 函数，看看你的编译器是如何处理函数中的错误的。

#include <string>

using std::string;

bool str_subrange(const string &str1, const string &str2) {
    if (str1.size() == str2.size())
        return str1 == str2;

    auto size = (str1.size() < str2.size()) ? str1.size() : str2.size();
    for (decltype(size) i = 0; i != size; ++i) {
        if (str1[i] != str2[i])
            return;
    }
}

/*
* 编译代码时，编译器提示错误：
*/
// .\ex_6.30.cpp: In function 'bool str_subrange(const string&, const string&)':
// .\ex_6.30.cpp:14:13: error: return-statement with no value, in function returning 'bool' [-fpermissive]
//              return;
//              ^~~~~~
