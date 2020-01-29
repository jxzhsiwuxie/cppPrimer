//练习 1.22：读取多个具有相同 ISBN 的销售记录，输出所有记录的和。

#include <istream>
#include "Sales_item.h"

//利用重定向从 Sales_item_data 文件中读取多个具有相同 ISBN 的销售记录
int main(){
    Sales_item sumItem, valItem;
    std::cin >> sumItem;
    while(std::cin >> valItem)
        sumItem += valItem;
    std::cout << "所有销售记录的和为：" << std::endl;
    std::cout << sumItem << std::endl;

    return 0;
}