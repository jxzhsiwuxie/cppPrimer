#ifndef JXZ_SCAN_STRING_H_
#define JXZ_SCAN_STRING_H_

#include <iostream>
#include <string>

class ScanString {
   private:
    std::istream &is;
    std::string data;

   public:
    ScanString(std::istream &in = std::cin) : is(in){}
    ~ScanString() = default;

    std::string operator()() {
        std::getline(is, data);
        return data;
    }
};


#endif