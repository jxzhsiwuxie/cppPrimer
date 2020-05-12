#ifndef JXZ_PRINT_STRING_H_
#define JXZ_PRINT_STRING_H_

#include <iostream>
#include <string>

class PrintString {
   private:
    std::ostream &os;  //用于写入的目的流
    char sep;          //用于将不同输出隔开的字符
   public:
    PrintString(std::ostream &o = std::cout, char c = ' ') : os(o), sep(c) {}
    ~PrintString() = default;

    void operator()(const std::string &s) const { os << s << sep; }
};

#endif