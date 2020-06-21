//重写你的电话号码程序，使之允许在号码的三个部分之间放置任意多个空白字符。


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

bool valid(const smatch &m);

int main() {
    string phone = "(\\()?(\\d{3})(\\))?([-.])?[ ]*(\\d{3})([-.]?)[ ]*(\\d{4})";
    regex r(phone);
    smatch m;
    string s;

    while (getline(cin, s)) {
        for (sregex_iterator it(s.begin(), s.end(), r), end_it; it != end_it; ++it) {
            if (valid(*it))
                cout << "valid: " << it->str() << endl;
            else
                cout << "not valid: " << it->str() << endl;
        }
    }

    return 0;
}

bool valid(const smatch &m) {
    if (m[1].matched)
        return m[3].matched && (m[4].matched || m[4].str() == " ");
    else
        return !m[3].matched && m[4].str() == m[6].str();
}
