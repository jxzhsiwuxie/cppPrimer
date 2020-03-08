//练习 8.10：编写程序，将来自一个文件中的行保存在一个 vector<string> 中。
//然后使用一个 istringstream 从 vector 读取元素，每次读取一个单词。

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;

int main() {
    ifstream ifs("sales.txt");
    string line;
    vector<string> lines;

    while (getline(ifs, line))
        lines.push_back(line);

    istringstream iss(lines.at(0));

    string word;
    while (iss >> word)
        cout << word << " ";

    cout << endl;

    return 0;
}
