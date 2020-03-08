//练习 8.13：重写本节的电话号码程序，从一个命名文件而非 cin 读取数据。

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::getline;
using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;

struct PersonInfo {
    string name;
    vector<string> phones;
};

int main() {
    ifstream ifs("info.txt");

    string line, word;
    vector<PersonInfo> people;

    while (getline(ifs, line)) {
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
