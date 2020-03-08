//练习 8.4：编写函数，以读模式单开一个文件，将其内容读到一个 string 的 vector 中，将每一行作为一个独立的元素存于 vector 中。

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
        while (std::getline(ifs, str))
            svec.push_back(str);

    }
}
