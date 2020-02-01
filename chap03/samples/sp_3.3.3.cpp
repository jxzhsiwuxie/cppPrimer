//假设有一组成绩的集合，其中成绩的取值从 0 到 100。以 10 分为一个分数段，
//要求统计各个分数段各有多少个成绩。

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
        if (grade <= 100)
            ++scores[grade / 10];

    for (auto i = 0; i < scores.size(); ++i)
        cout << grades[i] << "分段的人数有 " << scores[i] << " 人。" << endl;

    return 0;
}
