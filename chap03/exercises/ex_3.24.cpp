//练习 3.24：请使用迭代器重做 3.3.3 节的最后一个练习。

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
        for (auto it = ivec.cbegin(); it != ivec.cend() - 1; ++it)
            cout << "第 " << (it - ivec.cbegin()) << " 个和第 " << (it - ivec.cbegin() + 1) << " 个元素的和为：" << *it + *(it + 1) << endl;

        cout << "------------------------------------" << endl;

        //输出首尾相对元素的和
        auto ib = ivec.cbegin(), ie = ivec.cend() - 1;
        while (ib < ie)
        {
            cout << "第 " << (ib - ivec.cbegin()) << " 个和第 " << (ie - ivec.cbegin()) << " 个元素的和为：" << *ib + *ie << endl;
            ++ib;
            --ie;
        }
        if (ib == ie)
            cout << "最中间的元素为：" << *ib << endl;
    }

    return 0;
}
