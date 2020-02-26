//练习 6.44：将 6.2.2 节的 isShort 函数改写成内联函数。

#include <string>

inline bool isShort(const std::string &s1, const std::string &s2) {
    return s1.size() < s2.size();
}
