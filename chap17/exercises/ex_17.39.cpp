//练习 17.39：对本节给出的 seek 程序，编写你自己的版本。

#include <cstddef>
#include <fstream>
#include <iostream>
#include <string>

using std::cerr;
using std::cout;
using std::endl;
using std::fstream;
using std::getline;
using std::size_t;
using std::string;

int main() {
    fstream inOut("some.txt", fstream::ate | fstream::in | fstream::out);
    if (!inOut) {
        cerr << "无法打开文件！" << endl;
        return EXIT_FAILURE;
    }

    auto end_mark = inOut.tellg();
    inOut.seekg(0, fstream::beg);

    size_t cnt = 0;
    string line;

    while (inOut && inOut.tellg() != end_mark && getline(inOut, line)) {
        cnt += line.size() + 1;
        auto mark = inOut.tellg();
        inOut.seekp(0, fstream::end);
        inOut << cnt;

        if (mark != end_mark)
            inOut << " ";
        inOut.seekg(mark);
    }

    inOut.seekp(0, fstream::end);
    inOut << "\n";

    return 0;
}