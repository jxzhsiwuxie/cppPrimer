//练习 9.46：重写上一题的函数，这次使用位置和长度来管理 string，并只用 insert。

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
    name.insert(0, prefix);
    auto sz = name.size();
    name.insert(sz, suffix);

    return name;
}
