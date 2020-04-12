//练习 11.13：在上一题的程序中，至少有 3 种创建 pair 的方法。编写此程序的三个版本，分别采用不同的方法创建 pair。
//解释你认为哪种形式最利于理解和编写，为什么？

#include <cstddef>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using std::cout;
using std::endl;
using std::make_pair;
using std::pair;
using std::size_t;
using std::string;
using std::vector;

using std::istream;
using std::istringstream;

void record_people1(istream &is) {
    vector<pair<string, size_t>> people;

    size_t age;
    string name;

    while (is >> name >> age)
        people.push_back(make_pair(name, age));

    cout << "总共有 " << people.size() << " 个人，分别是：" << endl;

    for (const auto &person : people)
        cout << "姓名：" << person.first << " 年龄：" << person.second << endl;
}

void record_people2(istream &is) {
    vector<pair<string, size_t>> people;

    size_t age;
    string name;

    while (is >> name >> age)
        people.push_back(pair<string, size_t>(name, age));

    cout << "总共有 " << people.size() << " 个人，分别是：" << endl;

    for (const auto &person : people)
        cout << "姓名：" << person.first << " 年龄：" << person.second << endl;
}

void record_people3(istream &is) {
    vector<pair<string, size_t>> people;

    size_t age;
    string name;

    while (is >> name >> age)
        people.push_back({name, age});

    cout << "总共有 " << people.size() << " 个人，分别是：" << endl;

    for (const auto &person : people)
        cout << "姓名：" << person.first << " 年龄：" << person.second << endl;
}

int main() {
    string name_age = "张三 21 李四 32 王五 43 赵六 54";
    istringstream iss1(name_age);
    istringstream iss2(name_age);
    istringstream iss3(name_age);

    record_people1(iss1);
    cout << "---------------------" << endl;

    record_people2(iss2);
    cout << "---------------------" << endl;

    record_people3(iss3);
    cout << "---------------------" << endl;

    return 0;
}


/*
* 使用 make_pair 最易于编写和理解。
*/
