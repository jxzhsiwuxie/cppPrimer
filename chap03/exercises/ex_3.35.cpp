//练习 3.35：编写一段程序，利用指针将数组中的元素置为 0。

#include <iostream>

int main()
{
    int ia[10];
    int *bptr = std::begin(ia), *eptr = std::end(ia);
    while (bptr != eptr)
        *(bptr++) = 0;

    for (auto n : ia)
        std::cout << n << " ";
    std::cout << std::endl;

    return 0;
}
