//练习 16.23：预测在你的查询主程序中何时会执行调用运算符。如果你的预测和实际不符，确认你理解了原因。

#include <fstream>
#include <iostream>
#include <string>

#include "QueryResult.h"
#include "TextQuery.h"
#include "DebugDelete.h"

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::string;

void runQueries(ifstream &infile) {
    TextQuery tq(infile);
    while (true) {
        cout << "enter word to look for, or q to quit: ";
        string s;
        if (!(cin >> s) || s == "q")
            break;
        print(cout, tq.query(s)) << endl;
    }
}

int main() {
    ifstream ifs("data.txt");
    runQueries(ifs);

    return 0;
}