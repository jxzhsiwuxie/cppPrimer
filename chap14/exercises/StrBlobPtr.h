#ifndef STR_BLOB_PTR_H_
#define STR_BLOB_PTR_H_

#include <cstddef>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

#include "StrBlob.h"

class StrBlobPtr {
    friend bool operator==(const StrBlobPtr &, const StrBlobPtr &);
    friend bool operator!=(const StrBlobPtr &, const StrBlobPtr &);

   private:
    //若检查成功，check 返回一个指向 vector 的 shared_ptr
    std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string &) const;
    //保存一个 weak_ptr，意味着底层 vector 可能被销毁
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;  //在数组中的当前位置
   public:
    StrBlobPtr() : curr(0){};
    StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
    ~StrBlobPtr() = default;
    //deref 成员调用 check，检查使用 vector 是否安全以及 curr 是否在合法范围。
    std::string &deref() const;
    //前置递增，返回递增后的对象的引用
    StrBlobPtr &incr();

    std::string &operator[](std::size_t);
    std::string &operator[](std::size_t) const;

    //前置递增、递减运算符
    StrBlobPtr &operator++();
    StrBlobPtr &operator--();
    //后置递增、递减运算符
    StrBlobPtr &operator++(int);
    StrBlobPtr &operator--(int);

    StrBlobPtr &operator+(std::size_t);
    StrBlobPtr &operator+=(std::size_t);
    StrBlobPtr &operator-(std::size_t);
    StrBlobPtr &operator-=(std::size_t);
};

bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
    return *(lhs.wptr.lock()) == *(rhs.wptr.lock()) && lhs.curr == rhs.curr;
}

bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
    return !(lhs == rhs);
}

std::string &StrBlobPtr::operator[](std::size_t n) {
    return (*wptr.lock())[n];
}

std::string &StrBlobPtr::operator[](std::size_t n) const {
    return (*wptr.lock())[n];
}

StrBlobPtr &StrBlobPtr::operator++() {
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

StrBlobPtr &StrBlobPtr::operator--() {
    --curr;
    check(curr, "decrement past begin of StrBlobPtr");
    return *this;
}

StrBlobPtr &StrBlobPtr::operator++(int) {
    StrBlobPtr ret = *this;
    ++*this;
    return ret;
}

StrBlobPtr &StrBlobPtr::operator--(int) {
    StrBlobPtr ret = *this;
    --*this;
    return ret;
}

StrBlobPtr &StrBlobPtr::operator+=(std::size_t n) {
    check(n - 1, "increment past end of StrBlobPtr");
    check(curr - n + 1, "increment past end of StrBlobPtr");
    curr += n;
    return *this;
}

StrBlobPtr &StrBlobPtr::operator+(std::size_t n) {
    StrBlobPtr ret = *this;
    ret += n;
    return ret;
}

StrBlobPtr &StrBlobPtr::operator-=(std::size_t n) {
    curr -= n;
    check(curr, "decrement past begin of StrBlobPtr");
    return *this;
}

StrBlobPtr &StrBlobPtr::operator-(std::size_t n) {
    StrBlobPtr ret = *this;
    ret -= n;
    return ret;
}

#endif