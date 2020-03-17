//练习 9.45：编写一个函数，接受一个表示名字的 string 参数和两个分别表示前缀（如 “Mr.” 或 “Ms.”）和后缀（如“Jr.” 或 “III”）的字符串。
//使用迭代器及 insert 和 append 函数将将前缀和后缀添加到指定的名字中，将生成的新 stirng 返回。

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

string &genName(string &, const string &, const string &);

int main() {
    string name, prefix, suffix;

    cout << "输入一个英文姓名：";
    cin >> name;

    cout << "输入一个英文前缀（如 Mr. 或者 Ms.）：";
    cin >> prefix;

    cout << "输入一个英文后缀（如 Jr.）：";
    cin >> suffix;

    genName(name, prefix, suffix);

    cout << "完整的称呼为：" << name << endl;

    return 0;
}

string &genName(string &name, const string &prefix, const string &suffix) {
    cout << "名字为：" << name << "，前缀为：" << prefix << "，后缀为：" << suffix << endl;
    name.insert(name.begin(), prefix.begin(), prefix.end());
    name.append(suffix);

    return name;
}
