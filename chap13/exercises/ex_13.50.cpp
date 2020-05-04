//练习 13.50：在你的 String 类的移动操作中添加打印语句，并重新运行 13.6.1 节（第 437 页）的练习 13.48 中的程序，
//它使用了一个 vector<String>，观察什么时候会避免拷贝。

#include <utility>
#include "String.h"

int main() {
    String s1("dassaadas");

    std::vector<String>svec;
    svec.push_back(s1);
    svec.push_back(s1);
    svec.push_back(std::move(s1));
    svec.push_back(std::move(s1));

    return 0;
}
