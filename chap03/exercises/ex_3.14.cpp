//练习 3.14：编写一段程序，用 cin 读入一组整数并把它们存入一个 vector 对象。

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<int> ivec;
    int tmp = 0;
    cout << "输入一组整数，用空格分隔：" << endl;

    while (cin >> tmp)
        ivec.push_back(tmp);

    cout << "总共读取了 " << ivec.size() << " 个整数。" << endl;

    return 0;
}

