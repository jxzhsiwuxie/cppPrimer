//练习 3.31：编写一段程序，定义一个含有 10 个 int 的数组，令每个元素的值就是其下标值。

#include <iostream>
#include <cstddef>

int main()
{
    int ia[10];
    for (std::size_t i = 0; i < 10; i++)
        ia[i] = i;

    for (auto i : ia)
        std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}
