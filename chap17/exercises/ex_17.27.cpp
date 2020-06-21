//练习 17.27：编写程序，将九位数字的邮政编码的格式转为 ddddd-dddd。


#include <algorithm>
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

bool valid(const smatch &m);

int main() {
    string code = "(\\d{5})([-])?(\\d{4})?";
    regex r(code);
    smatch m;
    string s;
    string fmt = "$1-$3";

    while (getline(cin, s)) {
        if (regex_match(s, m, r)) {
            // m.format(fmt, format_no_copy);
            if (valid(m))
                cout << "valid: " << m.format(fmt, format_no_copy) << endl;
            else
                cout << "not valid: " << s << endl;
        } else {
            cout << "not valid: " << s << endl;
        }
    }

    return 0;
}

bool valid(const smatch &m) {
    if (m[2].matched)
        return m[1].matched && m[3].matched;
    else
        return m[1].matched && !m[3].matched;
}
