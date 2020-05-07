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
};

bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
    return lhs.wptr.lock() == rhs.wptr.lock() && lhs.curr == rhs.curr;
}

bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
    return !(lhs == rhs);
}

#endif