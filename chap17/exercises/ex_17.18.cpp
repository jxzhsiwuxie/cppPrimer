//练习 17.18：修改你的程序，忽略包含 “ei” 但并非 拼写错误的单词，如 “albeit” 和 “neighbor”。

#include <iostream>
#include <regex>
#include <string>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::find;

using std::regex;
using std::regex_match;
using std::regex_replace;
using std::regex_search;
using std::smatch;
using std::sregex_iterator;

int main() {
    regex pattern("[[:alnum:]]*[^c]ei[[:alnum:]]*", regex::icase);
    vector<string> ignores = {"albeit", "neighbor"};

    string file("iriweorweo iiweiffsdweir rewrw albeit sp'wfewi wi rwei jjewworeiwrjr neighbor werweior iwr ");

    for (sregex_iterator it(file.begin(), file.end(), pattern), ent_it; it != ent_it; ++it) {
        if(find(ignores.cbegin(), ignores.cend(),it->str()) != ignores.cend())
            continue;

        auto pos = it->prefix().length();
        pos = pos > 40 ? pos - 40 : 0;
        cout << it->prefix().str().substr(pos)
             << "\n\t\t>>> " << it->str() << " <<<\n"
             << it->suffix().str().substr(0, 40)
             << endl;
    }

    return 0;
}