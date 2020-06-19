//练习 17.14：编写几个正则表达式，分别触发不同错误。运行你的程序，观察编译器对每个错误的输出。

#include <iostream>
#include <regex>
#include <string>

using std::cout;
using std::endl;
using std::string;

using std::regex;
using std::regex_match;
using std::regex_replace;
using std::regex_search;
using std::smatch;

int main() {
    try {
        regex r0("[[:alnum:]]+\\.(cpp|cxx|cc)$", regex::icase);
        string filename("dasdsads.cpp");
        smatch results;

        // regex r1("[[:alnum]]+\\.(cpp|cxx|cc)$", regex::icase);
        // regex r2("[[:lnum:]]+\\.(cpp|cxx|cc)$", regex::icase);
        // regex r3("[[:alnum:]]+\\.cpp|cxx|cc)$", regex::icase);
        // regex r4("[[:alnum:]+\\.(cpp|cxx|cc)$", regex::icase);

        cout << regex_search(filename, results, r0) << endl;
        cout << results.str() << endl;

    } catch (const std::regex_error& e) {
        std::cerr << e.what() << "\ncode: " << e.code() << endl;
    }

    return 0;
}