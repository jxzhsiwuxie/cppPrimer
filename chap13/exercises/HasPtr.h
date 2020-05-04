#ifndef HAS_PTR_H_
#define HAS_PTR_H_

#include <iostream>
#include <memory>
#include <string>
#include <utility>

class HasPtr {
   public:
    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
    //拷贝构造函数
    HasPtr(const HasPtr &rhs) : ps(new std::string(*rhs.ps)), i(rhs.i) {}
    // HasPtr(const HasPtr &rhs) : ps(rhs.ps), i(rhs.i) {}

    HasPtr(HasPtr &&p) noexcept : ps(p.ps), i(p.i) { p.ps = nullptr; }

    ~HasPtr() {
        delete ps;
        ps = nullptr;
    }

    //拷贝赋值运算符
    // HasPtr &operator=(const HasPtr &rhs) {
    //     auto newP = new std::string(*rhs.ps);
    //     delete ps;

    //     ps = newP;
    //     i = rhs.i;

    //     return *this;
    // }

    // HasPtr &operator=(HasPtr &&rhs) {
    //     swap(*this, rhs);

    //     return *this;
    // }

    //当传入的实参是左值时，调用拷贝构造函数初始化形参；
    //当传入的实参右值时，调用移动构造函数初始化形参。
    HasPtr &operator=(HasPtr rhs) {
        swap(*this, rhs);

        return *this;
    }

    bool operator<(const HasPtr &rhs) {
        return *ps < *(rhs.ps);
    }

    std::string getString() const { return *ps; }
    void updateString(const char *ch) { ps->append(ch); }

    //swap 函数
    friend void swap(HasPtr &, HasPtr &);

   private:
    std::string *ps;
    int i;
};

inline void swap(HasPtr &lhs, HasPtr &rhs) {
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
}

#endif