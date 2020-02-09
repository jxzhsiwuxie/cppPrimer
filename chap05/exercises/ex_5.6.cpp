//练习 5.6：改写上一题的程序，使用条件运算符代替 if else 语句。

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
        score == 100 ? grade = "A++" : score >= 90 ? grade = "A" : score >= 80 ? grade = "B" : score >= 70 ? grade = "C" : score >= 60 ? grade = "D" : grade = "F";
        score == 100 ? grade += "" : score % 10 < 3 ? grade += "-" : score % 10 > 7 ? grade += "+" : grade += "";

        cout << "成绩分数为：" << score << "，对应的等级为：" << grade << endl;
    }

    return 0;
}
