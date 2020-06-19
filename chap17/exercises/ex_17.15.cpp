//练习 17.15：编写程序，使用模式查找违反 “i 在 e 之前，除非在 c 之后” 规则的单词。你的程序应该提示用户输入一个单词
//然后指出此单词是否符合要求。用一些违反和未违反规则的单词测试你的程序。

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

int main() {
    regex pattern("[[:alnum:]]*[^c]ei[[:alnum:]]*", regex::icase);
    string word;

    cout << "输入一个单词：";
    while (cin >> word) {
        if (regex_search(word, pattern)) {
            cout << "单词违反规则，再输入一个：";
        } else {
            cout << "单词符合规则" << endl;
            break;
        }
    }

    return 0;
}