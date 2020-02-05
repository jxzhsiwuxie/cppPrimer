//假设全班有 30 个学生，老师每周都会进行一次测验，测验的结果只有通过和不通过两种。

#include <iostream>

int main() {
    //使用 unsigned long 一方面确保 quizl 确实有 30 位，
    //另一方面尽量确保只对无符号类型做位运算
    unsigned long quizl = 0;

    //生成一个值，该值只有第 8 位为1，其它位都是 0（1UL << 8）
    //设置第 8 位同学测验通过
    quizl |= 1UL << 8;

    //生成一个值，该值只有第 8 位为 0，其它位都是 1（~(1UL << 8)）
    //设置第 8 位同学测验没通过
    quizl &= ~(1UL << 8);

    unsigned int tmp = 31;

    std::cout << "输入几个数字（不大于30的正整数）表示哪些学生通过了测验：" << std::endl;
    while (std::cin >> tmp) {
        if (tmp < 31 && tmp > 0)
            quizl |= 1UL << tmp - 1;
    }

    for (unsigned int n = 0; n < 30; ++n) {
        if (quizl & (1UL << n))
            std::cout << "恭喜第 " << n + 1 << " 位同学通过了测验" << std::endl;
        else
            std::cout << "第 " << n + 1 << " 位同学没有通过了测验" << std::endl;
    }

    return 0;
}
