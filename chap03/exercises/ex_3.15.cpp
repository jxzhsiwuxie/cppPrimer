//练习 3.15：改写上一题的程序，不过这次读入的是字符串。

#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    vector<string> ivec;
    string tmp;
    cout << "输入一组字符串，用空格分隔：" << endl;

    while (cin >> tmp)
        ivec.push_back(tmp);

    cout << "总共读取了 " << ivec.size() << " 个字符串。" << endl;

    return 0;
}
