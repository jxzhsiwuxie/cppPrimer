//练习 4.22：本节的示例程序将成绩划分成 high pass、pass 和 fail
//三种，扩展该程序使其进一步将 60 分到 75 分之间的成绩设定为 low
// pass。要求程序包含两个版本：一个版本只使用条件运算符； 另一个版本使用 1
//个或多个 if 语句。哪个版本的程序更容易理解呢？为什么？

#include <iostream>
#include <string>

int main() {
    using std::cin;
    using std::cout;
    using std::endl;
    using std::string;

    float grade = 0.0;
    string finalgrade1, finalgrade2;

    cout << "输入一个成绩（100分制：）";
    if (!(cin >> grade) || grade < 0 || grade > 100)
        cout << "输入无效" << endl;
    else {
        //版本1
        finalgrade1 = (grade > 90) ? "high pass" : (grade >= 60 && grade < 75) ? "low pass" : (grade < 60) ? "fail" : "pass";

        //版本2
        if (grade > 90)
            finalgrade2 = "high pass";
        else if (grade >= 60 && grade < 75)
            finalgrade2 = "low pass";
        else if (grade > 75)
            finalgrade2 = "pass";
        else
            finalgrade2 = "fail";

        cout << "最终成绩：版本1 " << finalgrade1 << "；版本2 " << finalgrade2 << endl;
    }

    return 0;
}

/*
* 显然版本 2 更容易理解，条件与对应的结果非常直观。
*/
