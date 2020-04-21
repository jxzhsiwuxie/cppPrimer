//练习 12.16：练习 12.16：如果你试图拷贝或赋值 unique_ptr，编译器并不是总能给出易于理解的错误信息。
//编写包含这种错误的程序，观察编译器如何诊断这种错误。

#include <memory>

using std::unique_ptr;

int main(){
    unique_ptr<int> up1;
    unique_ptr<int> up2(new int(100));

    // unique_ptr<int> up3(up2);

    // unique_ptr<int> up4 = up2;

    return ;
}
