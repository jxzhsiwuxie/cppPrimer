//练习 11.12：编写程序，读入 string 和 int 的序列，将每个 string 和 int 存入一个 pair 中，pair 保存在一个 vector 中。

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

using std::istringstream;

int main() {
    vector<pair<string, size_t>> people;
    string name_age = "张三 21 李四 32 王五 43 赵六 54";

    istringstream iss(name_age);

    size_t age;
    string name;

    while (iss >> name >> age)
        people.push_back(make_pair(name, age));

    cout << "总共有 " << people.size() << " 个人，分别是：" << endl;

    for (const auto &person : people)
        cout << "姓名：" << person.first << " 年龄：" << person.second << endl;

    return 0;
}
