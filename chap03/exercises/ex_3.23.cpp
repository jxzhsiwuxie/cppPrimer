//练习 3.23：编写一段程序，创建一个含有 10 个整数的 vector 对象，然后利用迭代器
//将所有元素的值都变为原来的两倍。输出 vector 对象的内容，检查程序是否正确。

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
    vector<int> ivec(10, 100);
    cout << "修改前数字为：" << endl;
    for (auto it = ivec.cbegin(); it != ivec.cend(); ++it)
        cout << *it << " ";
    cout << endl;

    for (auto it = ivec.begin(); it != ivec.end(); ++it)
        *it *= 2;

    cout << "修改后数字为：" << endl;
    for (auto it = ivec.cbegin(); it != ivec.cend(); ++it)
        cout << *it << " ";
    cout << endl;

    return 0;
}
