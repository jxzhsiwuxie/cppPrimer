//练习 8.11：本节程序在外层的 while 循环中定义了 istrirngstream 对象。如果 record 定义在循环之外，
//你需要对程序进行怎样的修改？重写程序，将 record 的定义移到 while 循环之外，验证你修改的方法是否正确。

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::istringstream;
using std::string;
using std::vector;

struct PersonInfo {
    string name;
    vector<string> phones;
};

int main() {
    cout << "输入一组联系人信息，每行一条，例如" << endl;
    cout << "zhangsan 18000566543" << endl;

    string line, word;
    vector<PersonInfo> people;

    istringstream record;

    while (getline(cin, line)) {
        PersonInfo info;

        //将 record 与 line 的拷贝绑定
        record.str(line);

        record >> info.name;

        while (record >> word)
            info.phones.push_back(word);

        people.push_back(info);

        //将 record 的状态重置留给循环的下一次使用
        record.clear();
    }

    if (people.size()) {
        cout << "一共读取了 " << people.size() << " 条信息" << endl;

        for (const auto &info : people)
            cout << "姓名：" << info.name << "，联系电话：" << info.phones.at(0) << endl;
    }

    return 0;
}
