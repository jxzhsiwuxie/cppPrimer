//练习 17.12：利用前一题中的数据结构，编写一个函数，它接受一个问题编号和一个表示真/假解答的值，函数根据这两个参数更新测验的解答。

#include <bitset>

std::bitset<100> ans;

void setAns(const unsigned no, const bool an) {
    ans.set(no, an);
}