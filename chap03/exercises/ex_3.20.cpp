//练习 3.20：读入一组整数并把它们存入一个 vector 对象，将每队相邻整数的和输出出来。
//改写你的程序，这次要求先输出第 1 个和对吼 1 个元素的和，接着输出第 2 个和倒数第 2 个元素的和。以此类推。

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

    if (!ivec.empty())
    {
        cout << "输入整数的个数为：" << ivec.size() << endl;
        cout << "------------------------------------" << endl;

        //输出相邻整数的和
        for (decltype(ivec.size()) i = 0; i < ivec.size() - 1; i++)
            cout << "第 " << i << " 个和第 " << i + 1 << " 个元素的和为：" << ivec[i] + ivec[i + 1] << endl;

        cout << "------------------------------------" << endl;

        //输出首尾相对元素的和
        vector<int>::size_type ib = 0, ie = ivec.size() - 1;
        while (ib < ie)
        {
            cout << "第 " << ib << " 个和第 " << ie << " 个元素的和为：" << ivec[ib] + ivec[ie] << endl;
            ++ib;
            --ie;
        }
        if (ib == ie)
            cout << "最中间的元素为：" << ivec[ib] << endl;
    }

    return 0;
}
