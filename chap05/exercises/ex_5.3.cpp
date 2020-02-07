//练习 5.3：使用逗号运算符重写 1.4.1 节的 while 循环，使它不再需要块，观察改写之后的代码可读性是提高了还是降低了。

#include <iostream>

//原来的程序
// int main() {
//     int sum = 0, val = 1;
//     while (val <= 10) {
//         sum += val;
//         ++val;
//     }
//     std::cout << "Sum of 1 to 10 inclusive is " << sum << std::endl;

//     return 0;
// }

//修改后程序
int main() {
    int sum = 0, val = 1;
    while (val <= 10)
        sum += val, ++val;

    std::cout << "Sum of 1 to 10 inclusive is " << sum << std::endl;

    return 0;
}
