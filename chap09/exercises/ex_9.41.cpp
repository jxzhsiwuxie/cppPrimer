//练习 9.41：编写程序，从一个 vector<char> 初始化一个 stirng。

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
    vector<char> chVec = {'H', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd'};
    cout << "vector 中的字符为：" << endl;
    for (auto c : chVec)
        cout << c;
    cout << endl;

    string s(chVec.begin(), chVec.end());
    cout << "初始化得到的 string 为：" << endl;
    cout << s << endl;

    return 0;
}
