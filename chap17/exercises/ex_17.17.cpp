//练习 17.17：更新你的程序，令它查找输入序列中所有违反 “ei” 语法规则的单词。

#include <iostream>
#include <regex>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

using std::regex;
using std::regex_match;
using std::regex_replace;
using std::regex_search;
using std::smatch;
using std::sregex_iterator;

int main() {
    regex pattern("[[:alnum:]]*[^c]ei[[:alnum:]]*", regex::icase);
    string file("iriweorweo iiweiffsdweir rewrw  sp'wfewi wi rwei jjewworeiwrjr werweior iwr ");
    
    for(sregex_iterator it(file.begin(), file.end(), pattern), ent_it; it != ent_it; ++it){
        auto pos = it->prefix().length();
        pos = pos > 40 ? pos - 40 : 0;
        cout << it->prefix().str().substr(pos)
            << "\n\t\t>>> " << it->str() << " <<<\n"
            << it->suffix().str().substr(0, 40)
            << endl;
    }

    return 0;
}