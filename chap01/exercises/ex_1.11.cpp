//练习 1.11：编写程序，提示用户输入两个整数，
//打印出这两个整数所指定的范围内的所有整数。

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