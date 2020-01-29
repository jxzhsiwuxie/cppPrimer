//练习 1.20：在网站 http://www.informit.com/store/c-plus-plus-primer-9780321714114 上，
//第一章的代码目录中包含了头文件 Sales_item.h。将它拷贝到你自己的工作目录中。
//用它编写一个程序，读取一组书籍销售记录，将每条记录打印到标准输出上。

#include <iostream>
#include "Sales_item.h"

int main(){
    std::cout << "输入一组书籍销售记录（ISBN号 销售册数 每册价格）：" << std::endl;
    Sales_item item;
    std::cin >> item;
    std::cout << "刚才输入的书籍销售记录为：" << std::endl;
    std::cout << item << std::endl;

    return 0;
}