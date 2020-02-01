//练习 3.22：修改之前那个输出 text 第一段的程序，首先把 text 第一段全都改成大写形式，然后再输出它。

#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    vector<string> text;
    //将文本内容存入 text

    for (auto it = text.begin(); it != text.end() && !it->empty(); ++it)
    {
        for (auto &c : *it)
            c = std::toupper(c);
        cout << *it << endl;
    }

    return 0;
}
