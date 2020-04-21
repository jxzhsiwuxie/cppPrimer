#include "StrBlobPtr.h"

std::shared_ptr<std::vector<std::string>> StrBlobPtr::check(std::size_t i, const std::string &msg) const {
    // vector 是否还存在
    auto ret = wptr.lock();
    if (!ret)
        throw std::runtime_error("unbound StrBlobPtr");
    if (i > ret->size() - 1)
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
