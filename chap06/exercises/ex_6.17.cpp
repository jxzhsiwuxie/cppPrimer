//练习 6.17：编写一个函数，判断 string 对象中是否含有大写字母。编写另一个函数，把 string 对象全都改成小写形式。
//在在这两个函数中，你使用的形参类型相同么？为什么？

#include <cctype>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

//检测 stirng 对象中是否有大写字母
bool hasUpper(const string &s);

//将 stirng 对象改成小写
void toLower(string &s);

int main() {
    string s;
    cout << "输入一个英文单词：";
    if (cin >> s) {
        cout << (hasUpper(s) ? "有" : "没有") << "大写字母" << endl;

        toLower(s);
        cout << "变成小写之后为：" << s << endl;
    }

    return 0;
}

bool hasUpper(const string &s) {
    bool result = false;
    for (const auto &c : s) {
        if (isupper(c)) {
            result = true;
            break;
        }
    }
    return result;
}

void toLower(string &s) {
    for (auto &c : s)
        c = tolower(c);
}


/*
* 形参类型不一样。
* 判断是否有大写字母的函数不需要修改实参 stirng 对象，所以使用 const string & 类型；
* 将 string 对象改为小写的函数显然需要修改实参 string 对象的值，所以只能使用普通引用的形参。
*/
