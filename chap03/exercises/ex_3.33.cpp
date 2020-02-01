//练习 3.33：对于 104 页的程序来说，如果不初始化 scores 将发生什么？

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    unsigned scores[11] = {};
    unsigned grade;
    while (cin >> grade)
        if (grade <= 100)
            ++scores[grade / 10];

    for (auto n : scores)
        cout << n << " ";
    cout << endl;

    return 0;
}

/*
* 如果不初始化 scores，scores 中的 11 个元素将会都是未定义的值，此时执行 
* ++scores[grade / 10];
* 将对应分段的值加一根本毫无意义。
*/