//练习 13.44：编写标准库 string 类的简化版本，命名为 String。你的类应该至少有一个默认构造函数和一个接受 C 风格字符串指针的构造函数。
//使用 allocator 为你的 String 类分配所需内存。

#include <algorithm>
#include <cstddef>
#include <cstring>
#include <iostream>
#include <iterator>
#include <memory>

class String {
    friend std::ostream &operator<<(std::ostream &, const String &);

   private:
    char *contents;
    char *tail;
    static std::allocator<char> alloc;
    void free() {
        if (contents) {
            for (auto p = tail; p != contents;)
                alloc.destroy(--p);
            alloc.deallocate(contents, tail - contents);
        }
    }

   public:
    String() : contents(nullptr), tail(nullptr) {}
    String(const char *str) {
        auto n = std::strlen(str);
        auto data = alloc.allocate(n);
        contents = data;
        tail = std::uninitialized_copy(str, str + n, data);
    }
    String(const String &s) {
        auto n = s.size();
        auto data = alloc.allocate(n);
        contents = data;
        tail = std::uninitialized_copy(s.begin(), s.end(), data);
    }
    String &operator=(const String &rhs) {
        auto n = rhs.size();
        std::cout << n << std::endl;
        auto data = alloc.allocate(n);
        auto new_tail = std::uninitialized_copy(rhs.begin(), rhs.end(), data);
        free();
        contents = data;
        tail = new_tail;

        return *this;
    }

    ~String() { free(); }

    std::size_t size() const {
        return tail - contents;
    }

    bool empty() const { return size() == 0; }

    char *begin() const { return contents; }
    char *end() const { return tail; }
};
std::allocator<char> String::alloc;
std::ostream &operator<<(std::ostream &os, const String &s) {
    std::ostream_iterator<char> os_iter(os, "");
    std::copy(s.begin(), s.end(), os_iter);
    return os;
}

int main() {
    String s1("dassaadas");
    String s2(s1);
    String s3;
    s3 = String("dsaffsdf");

    std::cout << s1 << std::endl;
    std::cout << s2 << std::endl;
    std::cout << s3 << std::endl;

    return 0;
}