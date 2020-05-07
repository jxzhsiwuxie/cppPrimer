#ifndef JXZ_STRING_H_
#define JXZ_STRING_H_

#include <algorithm>
#include <cstddef>
#include <cstring>
#include <iostream>
#include <iterator>
#include <memory>
#include <vector>

class String {
    friend std::ostream &operator<<(std::ostream &, const String &);
    friend bool operator==(const String &, const String &);
    friend bool operator!=(const String &, const String &);

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

    String(String &&s) noexcept : contents(s.contents), tail(s.tail) {
        s.contents = s.tail = nullptr;
    }

    String &operator=(const String &rhs) {
        auto n = rhs.size();
        auto data = alloc.allocate(n);
        auto new_tail = std::uninitialized_copy(rhs.begin(), rhs.end(), data);
        free();
        contents = data;
        tail = new_tail;

        return *this;
    }

    String &operator=(String &&rhs) noexcept {
        if (this != &rhs) {
            free();
            contents = rhs.contents;
            tail = rhs.tail;

            rhs.contents = rhs.tail = nullptr;
        }
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

bool operator==(const String &lhs, const String &rhs) {
    return std::strcmp(lhs.contents, rhs.contents);
}

bool operator!=(const String &lhs, const String &rhs) {
    return !(lhs == rhs);
}

#endif