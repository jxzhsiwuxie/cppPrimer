//练习 8.5：重写上面的程序，将每个单词作为一个独立的元素进行存储。

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;
using std::vector;

void readFromFile(const string&, vector<string>&);

int main() {
    vector<string> svec;
    readFromFile("data", svec);

    if (svec.size()) {
        for (const auto& s : svec)
            cout << s << endl;
    } else {
        cout << "读取数据失败" << endl;
    }

    return 0;
}

void readFromFile(const string& path, vector<string>& svec) {
    ifstream ifs(path);
    if (ifs) {
        string str;
        while (ifs >> str)
            svec.push_back(str);
    }
}