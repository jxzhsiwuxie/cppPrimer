//练习 17.23：编写查找邮政编码的正则表达式。一个美国邮政编码可以由五位或九位数字组成。前五位和后四位之间可以用一个短横线分割。

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
    string code = "(\\d{5})([-])?(\\d{4})?";
    regex r(code);
    smatch m;
    string s;

    while (getline(cin, s)) {
        if (regex_match(s, m, r)) {
            if (valid(m))
                cout << "valid: " << m.str() << endl;
            else
                cout << "not valid: " << s << endl;
        } else {
            cout << "not valid: " << s << endl;
        }
    }

    return 0;
}

bool valid(const smatch &m) {
    cout << "m[2].matched = " << m[2].matched << endl;
    if (m[2].matched)
        return m[1].matched && m[3].matched;
    else
        return m[1].matched && !m[3].matched;
}
