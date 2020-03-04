//练习 7.43：假设有一个名为 NoDefault 的类，它有一个接受 int 的构造函数，但是没有默认构造函数。
//定义类 C，C 有一个 NoDefault 类型的成员，定义 C 的默认构造函数。

#include <iostream>

class NoDefault {
   private:
    int val;

   public:
    NoDefault(int n) : val(n) {}
    int getVal() const { return val; }
};

class C {
   private:
    NoDefault item;

   public:
    C() : item(0) {}
    NoDefault getItem() const { return item; }
};

int main() {
    C defaultC;

    std::cout << defaultC.getItem().getVal() << std::endl;

    return 0;
}
