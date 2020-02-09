//练习 5.5：写一段自己的程序，使用 if else 语句实现把数字成绩转换成字母成绩的要求。
//其中 100 分是 A++，低于 60 分对应 F，其它成绩每 10 分划分一组：60 分 到 69 分（包括 69）对应字母 D……
//如果成绩的末尾是 8 或 9 添加一个 + 号，如果成绩的末尾是 0、1 或 2 则添加一个 - 号。

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
    unsigned int score = 0;
    string grade = "F";

    cout << "输入一个 0~100 之间的整数：";
    if (!(cin >> score) || score < 0 || score > 100) {
        cout << "输入内容无效" << endl;
        return -1;
    } else {
        if (score < 60)
            grade = "F";
        else if (score >= 60 && score < 70) {
            grade = "D";
            if (score % 10 == 0 || score % 10 == 1 || score % 10 == 2)
                grade += '-';
            else if (score % 10 == 8 || score % 10 == 9)
                grade += '+';
        } else if (score >= 70 && score < 80) {
            grade = "C";
            if (score % 10 == 0 || score % 10 == 1 || score % 10 == 2)
                grade += '-';
            else if (score % 10 == 8 || score % 10 == 9)
                grade += '+';
        } else if (score >= 80 && score < 90) {
            grade = "B";
            if (score % 10 == 0 || score % 10 == 1 || score % 10 == 2)
                grade += '-';
            else if (score % 10 == 8 || score % 10 == 9)
                grade += '+';
        } else if (score >= 90 && score < 100) {
            grade = "A";
            if (score % 10 == 0 || score % 10 == 1 || score % 10 == 2)
                grade += '-';
            else if (score % 10 == 8 || score % 10 == 9)
                grade += '+';
        } else {
            grade = "A++";
        }

        cout << "成绩分数为：" << score << "，对应的等级为：" << grade << endl;
    }

    return 0;
}
