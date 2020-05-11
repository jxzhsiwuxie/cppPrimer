//练习 14.32：定义一个类，令其含有一个指向 StrBlobPtr 对象的指针，为这个类定义重载的箭头运算符。

#include "StrBlobPtr.h"

class HasStrBlobPtr {
   private:
    StrBlobPtr *ptr;

   public:
    HasStrBlobPtr(StrBlobPtr *strblobptr_ptr) : ptr(strblobptr_ptr) {}

    StrBlobPtr *operator->() const { return ptr; }
};
