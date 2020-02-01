//练习 3.36：编写一段程序，比较两个数组是否相等。再写一段程序，比较两个 vector 对象是否相等。

#include <iostream>
#include <vector>

int main()
{
    using std::cout;
    using std::endl;
    using std::vector;

    const int len1 = 7, len2 = 6;
    int ia1[len1] = {1, 2, 3, 4, 5, 6, 7};
    int ia2[len2] = {1, 2, 3, 4, 5, 6};

    vector<int> ivec1 = {1, 2, 3, 4, 5, 6, 7};
    vector<int> ivec2 = {1, 2, 3, 4, 5, 6, 8};

    if (len1 != len2)
    {
        cout << "两个数组不相等" << endl;
    }
    else
    {
        bool b = true;
        for (int i = 0; i < len1; i++)
        {
            if (ia1[i] != ia2[i])
                b = false;
        }

        cout << "两个数组" << (b ? "相等" : "不相等") << endl;
    }

    cout << "两个vector " << (ivec1 == ivec2 ? "相等" : "不相等") << endl;

    return 0;
}
