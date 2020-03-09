//练习 9.14：编写程序，将一个 list 中的 char * 指针（指向 C 风格字符串）元素赋值给一个 vector 中的 string。

#include <iostream>
#include <list>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::list;
using std::string;
using std::vector;

int main() {
    list<const char*> cStrList = {"abc", "fed", "ihj"};

    cout << "原始的 list<char*> 中的内容为：" << endl;
    for (const auto& s : cStrList)
        cout << s << " ";
    cout << endl;

    vector<string> strings0(cStrList.begin(), cStrList.end());
    cout << "使用初始化的方式得到的 vector<string>  中的内容为：" << endl;
    for (const auto& s : strings0)
        cout << s << " ";
    cout << endl;

    vector<string> strings1;
    strings1.assign(cStrList.begin(), cStrList.end());
    cout << "使用 assign 的方式得到的 vector<string>  中的内容为：" << endl;
    for (const auto& s : strings1)
        cout << s << " ";
    cout << endl;

    return 0;
}
