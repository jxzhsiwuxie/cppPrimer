//练习 5.19：编写一段程序，使用 do while 循环重复地执行下述任务：首先提示用户输入两个 string 对象，
//然后挑出较短的那个并输出它。

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
    string s1, s2;

    do {
        cout << "输入两句话，用空格隔开：" << endl;
    } while (cin >> s1 >> s2);

    if (s1.size() == s2.size())
        cout << "两句话一样长。" << endl;
    else if (s1.size() < s2.size())
        cout << "第一句话比较短。" << endl;
    else
        cout << "第二句话比较短。" << endl;

    return 0;
}
