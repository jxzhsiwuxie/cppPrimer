//练习 5.21：修改 5.5.1 节练习题的程序，使其找到的重复单词必须以大写字母开头。

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
    string s1, s2;

    cout << "输入一句话：" << endl;
    if (cin >> s1) {
        while (cin >> s2) {
            if (!std::isupper(s2.at(0)))
                continue;

            if (s1 == s2)
                break;
            else
                s1 = s2;
        }
    }

    if (cin)
        cout << s1 << " 连续出现了两次。" << endl;
    else
        cout << "没有单词连续出现了两次。" << endl;

    return 0;
}
