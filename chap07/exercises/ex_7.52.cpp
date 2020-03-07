//练习 7.52：使用 2.6.1 节（第 64 页）的 Sales_data 类，解释下面的初始化过程。如果存在问题，尝试修改它。
// Sales_data item = {"978-0590353403", 25, 15.99};

/*
* 按照 2.6.1 节定义的 Sales_data 不是聚合类（有类内初始值），按说不能使用值列表初始化，实际测试又是可以的。
*/

#include <iostream>
#include <string>

struct Sales_data {
    std::string bookNo;
    unsigned units_solid = 0;
    double revenue = 0.0;
};

int main() {
    Sales_data item = {"978-0590353403", 25, 15.99};

    std::cout << "item 的 isbn 为：" << item.bookNo << "， "
              << "item 的 units_solid 为：" << item.units_solid << "， "
              << "item 的 revenue 为：" << item.revenue << std::endl;

    return 0;
}
