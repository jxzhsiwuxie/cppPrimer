//练习 17.25：重写你的电话号码程序，使之只输出每个人的第一个电话号码。


#include <fstream>
#include <iostream>
#include <regex>
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

using std::regex;
using std::regex_match;
using std::regex_replace;
using std::regex_search;
using std::smatch;
using std::sregex_iterator;

using std::sregex_iterator;

struct PersonInfo {
    string name;
    vector<string> phones;
};

bool valid(const string s) {
    string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ]?)(\\d{4})";
    regex r(phone);
    smatch m;

    if (!regex_match(s, m, r))
        return false;

    if (m[1].matched)
        return m[3].matched && (m[4].matched || m[4].str() == " ");
    else
        return !m[3].matched && m[4].str() == m[6].str();
}

int main() {
    ifstream ifs("info.txt");

    string line, word;
    vector<PersonInfo> people;

    while (getline(ifs, line)) {
        PersonInfo info;
        istringstream record(line);
        record >> info.name;

        while (record >> word)
            if (valid(word))
                info.phones.push_back(word);

        people.push_back(info);
    }

    if (people.size()) {
        cout << "一共读取了 " << people.size() << " 条信息" << endl;

        for (const auto &info : people)
            cout << "姓名：" << info.name << "，联系电话：" << (info.phones.size() ? info.phones.at(0) : "无正确的联系电话") << endl;
    }

    return 0;
}
