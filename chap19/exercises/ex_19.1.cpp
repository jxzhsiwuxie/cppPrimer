//练习 19.1：使用 malloc 编写你自己版本的 operator new(size_t) 函数，，使用 free 编写 operator delete(void *) 函数。

#include <cstdlib>
#include <stdexcept>

void *operator new(std::size_t size) {
    if (void *mem = std::malloc(size))
        return mem;
    else
        throw std::bad_alloc();
}

void operator delete(void *mem) noexcept {
    std::free(mem);
}
