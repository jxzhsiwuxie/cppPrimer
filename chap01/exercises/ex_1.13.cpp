//练习 1.13：使用 for 循环重做 1.4.1 节中的所有练习。

#include <iostream>

//练习 1.9：
// int main(){
//     int sum = 0;
//     for(int i = 50; i <= 100; i++)
//         sum += i;
//     std::cout << "50 到 100 之间所有整数的和为：" << sum << std::endl;

//     return 0;
// }


//练习 1.10：
// int main(){
//     for(int i = 10; i >= 0; i--)
//         std::cout << i << " ";
//     std::cout << std::endl;
//     return 0;
// }


//练习 1.11：
int main(){
    int v1 = 0, v2 = 0;
    std::cout << "请输入两个整数：";
    std::cin >> v1 >> v2;

    if(v1 > v2)
        for(int i = v2; i <= v1; i++)
            std::cout << i << " ";
    else
        for(int i = v1; i <= v2; i++)
            std::cout << i << " ";

    std::cout << std::endl;
    return 0;
}