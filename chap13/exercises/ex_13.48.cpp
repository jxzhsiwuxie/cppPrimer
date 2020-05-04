//练习 13.48：定义一个 vector<String> 并在其上多次调用 push_back。运行你的程序，观察 String 被拷贝了多少次。

#include <algorithm>
#include <cstddef>
#include <cstring>
#include <iostream>
#include <iterator>
#include <memory>
#include <vector>

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
        std::cout << "拷贝构造函数被调用了" << std::endl;
        auto n = s.size();
        auto data = alloc.allocate(n);
        contents = data;
        tail = std::uninitialized_copy(s.begin(), s.end(), data);
    }
    String &operator=(const String &rhs) {
        std::cout << "拷贝赋值运算符被调用了" << std::endl;
        auto n = rhs.size();
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

    std::vector<String>svec;
    svec.push_back(s1);
    svec.push_back(s1);
    svec.push_back(s1);
    svec.push_back(s1);

    return 0;
}
