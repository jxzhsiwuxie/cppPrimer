//练习 9.49：如果一个字母延伸到中线之上，如 d 或 f，则称其有上出头部分（ascender）。如果一个字母延伸到中线之下，如 p 或 g，则称其有下出头部分（desender）。
//编写程序，读入一个单词文件，输出最长的既不包含上出头部分，也不包含下出头部分的单词。

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::istringstream;
using std::string;

int main() {
    string ref("aceiklmnorstuvwxz"), theStr;

    ifstream ifs("data.txt");
    string word, line;
    string::size_type sz = 0;
    unsigned wordCount = 0, lineCount = 0;

    while (std::getline(ifs, line)) {
        ++lineCount;
        istringstream iss(line);
        while (iss >> word) {
            ++wordCount;
            if (word.find_first_not_of(ref) == string::npos) {
                if (word.size() > sz) {
                    sz = word.size();
                    theStr = word;
                }
            }
        }
    }

    cout << "总共读取了 " << lineCount << " 行 " << wordCount << " 个单词" << endl;
    if (sz)
        cout << "符合要求的最长的单词为：" << theStr << endl;
    else
        cout << "没有找到符合要求的单词" << endl;

    return 0;
}
