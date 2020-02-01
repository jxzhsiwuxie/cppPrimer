//练习3.25：3.3.3 节划分分数段的程序是使用下标运算符实现的，请利用迭代器改写程序并实现完全相同的功能。

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
    vector<unsigned> scores(11, 0);
    vector<string> grades{"0~9分", "10~19分", "20~29分", "30~39分", "40~49分", "50~59分", "60~69分", "70~79分", "80~89分", "90~99分", "100分"};
    unsigned grade;

    cout << "输入一组 0~100 的数字：" << endl;

    while (cin >> grade)
    {
        if (grade <= 100)
        {
            auto it = scores.begin() + grade / 10;
            ++(*it);
        }
    }

    auto it1 = scores.cbegin(), eit1 = scores.cend();
    auto it2 = grades.cbegin();
    while (it1 != eit1)
    {
        cout << *it2 << "分段的人数有 " << *it1 << " 人。" << endl;
        ++it1;
        ++it2;
    }

    return 0;
}
