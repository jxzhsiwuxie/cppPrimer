//练习 1.19：修改你为 1.4.1 节练习 1.11 所编写的程序（打印一个范围内的数），
//使其能处理用户输入的第一个数比第二个数小的情况。

#include <iostream>

int main(){
    std::cout << "请输入两个整数：" << std::endl;

    int v1 = 0, v2 = 0;

    std::cin >> v1 >> v2;

    if(v1 >= v2){
        std::cout << v2 << " 到 " << v1 << "之间的整数有：" << std::endl;
        while(v2 <= v1) std::cout << v2++ << " ";
    }else{
        std::cout << v1 << " 到 " << v2 << "之间的整数有：" << std::endl;
        while(v1 <= v2) std::cout << v1++ << " ";
    }
    std::cout << std::endl;
    return 0;
}