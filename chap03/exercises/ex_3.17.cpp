//练习 3.17：从 cin 读入一组词并把它们存入一个 vector 对象，然后设法把所有词都改写为大写形式。
//输出改变后的结果，每个词占一行。

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
    vector<string> svec;
    string tmp;
    cout << "输入一句话（只限于英文字母）：" << endl;
    while (cin >> tmp)
        svec.push_back(tmp);

    if (!svec.empty())
    {
        for (auto &s : svec)
        {
            for (auto &c : s)
                if (std::isalpha(c))
                    c = std::toupper(c);
        }

        cout << "改变之后的话为：" << endl;
        for (auto s : svec)
            cout << s << endl;
    }

    return 0;
}
