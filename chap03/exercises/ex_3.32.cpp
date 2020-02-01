//练习 3.32：将上提刚刚创建的数组拷贝给另外一个数组。利用 vector 重写程序，实现类似的功能。

#include <iostream>
#include <cstddef>
#include <vector>

using std::vector;

int main()
{
    const std::size_t arraySize = 10;
    int ia[arraySize];
    int ia2[arraySize];
    vector<int> ivec;

    for (std::size_t i = 0; i < arraySize; i++)
        ia[i] = i;

    //将 ia 中所有元素拷贝到 ia2 中
    for (std::size_t i = 0; i < arraySize; i++)
        ia2[i] = ia[i];

    //将 ia 中所有元素拷贝到 ivec 中
    for (auto i : ia)
        ivec.push_back(i);

    //打印三个对象中的元素
    for (auto i : ia)
        std::cout << i << " ";
    std::cout << std::endl;

    for (auto i : ia2)
        std::cout << i << " ";
    std::cout << std::endl;

    for (auto i : ivec)
        std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}
