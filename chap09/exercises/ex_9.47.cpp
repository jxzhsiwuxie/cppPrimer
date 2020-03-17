//练习 9.47：编写程序，首先查找 stirng "ab2c3d7R4E6" 中的每个数字字符，然后查找其中每个字母字符。
//编写两个版本的程序，第一个要使用 find_first_of，第二个要使用 find_first_not_of。

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

void findNumbers(const string &, const string &);
void findLetters(const string &, const string &);

int main() {
    string str("ab2c3d7R4E6"), ref("23467");
    findNumbers(str, ref);
    cout << "-------------------------------------" << endl;
    findLetters(str, ref);

    return 0;
}

void findNumbers(const string &str, const string &ref) {
    string::size_type pos = 0;
    while ((pos = str.find_first_of(ref, pos)) != string::npos) {
        cout << "在位置为 " << pos << " 处发现数字字符 " << str.at(pos) << endl;
        ++pos;
    }
}

void findLetters(const string &str, const string &ref) {
    string::size_type pos = 0;
    while ((pos = str.find_first_not_of(ref, pos)) != string::npos) {
        cout << "在位置为 " << pos << " 处发现字母字符 " << str.at(pos) << endl;
        ++pos;
    }
}
