//练习 3.41：编写一段程序，用整型数组初始化一个 vector 对象。

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main()
{
    const int ia[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    const vector<int> ivec(std::begin(ia), std::end(ia));

    cout << "数组中元素为：" << endl;
    for (auto n : ia)
        cout << n << " ";
    cout << endl;

    cout << "vector 中元素为：" << endl;
    for (auto n : ivec)
        cout << n << " ";
    cout << endl;

    return 0;
}
