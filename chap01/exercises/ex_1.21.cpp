//练习 1.21：编写程序，读取两个 ISBN 相同的 Sales_item 对象，输出它们的和。

#include <iostream>
#include "Sales_item.h"


int main(){
    std::cout << "输入两个 ISBN 相同的书籍销售记录，以空格分割：" << std::endl;
    Sales_item item1, item2;
    std::cin >> item1 >> item2;
    std::cout << "两个书籍销售记录的和为：" << std::endl;
    std::cout << item1 + item2 << std::endl;

    return 0;
}