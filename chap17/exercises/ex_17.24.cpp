//练习 17.24：编写你自己版本的重排电话号码格式的程序。

#include <iostream>
#include <regex>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::vector;

using std::regex;
using std::regex_match;
using std::regex_replace;
using std::regex_search;
using std::smatch;
using std::sregex_iterator;

using namespace std::regex_constants;

int main() {
    string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ]?)(\\d{4})";
    regex r(phone);
    smatch m;
    string s;
    string fmt = "$2.$5.$7";

    getline(cin, s);
    cout << regex_replace(s, r, fmt) << endl;

    return 0;
}
