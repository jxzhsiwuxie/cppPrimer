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

    ~HasPtr() {
        delete ps;
        ps = nullptr;
    }

    //拷贝赋值运算符
    HasPtr &operator=(const HasPtr &rhs) {
        auto newP = new std::string(*rhs.ps);
        delete ps;

        ps = newP;
        i = rhs.i;

        return *this;
    }

    bool operator<(const HasPtr &rhs) {
        std::cout << "HasPtr 对象的比较运算符被调用了" << std::endl;
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
    std::cout << "HasPtr 对象的 swap 函数被调用了" << std::endl;

    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
}

#endif