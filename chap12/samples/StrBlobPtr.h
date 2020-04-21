#ifndef STR_BLOB_PTR_H_
#define STR_BLOB_PTR_H_

#include <cstddef>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

#include "StrBlob.h"

class StrBlobPtr {
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
};

std::shared_ptr<std::vector<std::string>> StrBlobPtr::check(std::size_t i, const std::string &msg) const {
    // vector 是否还存在
    auto ret = wptr.lock();
    if (!ret)
        throw std::runtime_error("unbound StrBlobPtr");
    ;
    if (i >= ret->size() - 1)
        throw std::out_of_range(msg);
    return ret;  //否则返回指向 vector 的 shared_ptr
}

std::string &StrBlobPtr::deref() const {
    auto p = check(curr, "dereference past end");
    return (*p)[curr];  //(*p) 是 对象所指向的 vector
}

StrBlobPtr &StrBlobPtr::incr() {
    //如果 curr 已经指向对象的尾后位置，就不能递增它
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

#endif