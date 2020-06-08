//练习 17.13：编写一个整型对象，包含真/假测验的正确答案。使用它来为前两题中的数据结构生成测验成绩。

#include <bitset>

int main() {
    std::bitset<100> ans;
    //填入答案

    //正确答案。。。
    std::bitset<100> right;

    std::bitset<100> res = ~(ans ^ right);
    unsigned score = res.count();

    return 0;
}