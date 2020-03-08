//读取联系人的信息并存储。
//每条联系人有一个名字以及一个或者多个联系电话

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

    while (getline(cin, line)) {
        PersonInfo info;
        istringstream record(line);
        record >> info.name;

        while (record >> word)
            info.phones.push_back(word);

        people.push_back(info);
    }

    if (people.size()) {
        cout << "一共读取了 " << people.size() << " 条信息" << endl;

        for (const auto &info : people)
            cout << "姓名：" << info.name << "，联系电话：" << info.phones.at(0) << endl;
    }

    return 0;
}
