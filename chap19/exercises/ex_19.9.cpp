//练习 19.9：编写一个与本节最后一个程序类似的代码，令其打印你的编译器为一些常见类型所起的名字。如果你得到的输出结果与本书类似。
//尝试编写一个函数将这些字符串翻译成人们更容易读懂的形式。

#include <iostream>
#include <typeinfo>
#include <string>

using std::cout;
using std::endl;

class A {
   public:
    virtual ~A() = default;
};

class D : public A {
   public:
    virtual ~D() = default;
};

int main() {
    int arr[10];
    D d;
    A *a = &d;

    cout << typeid(42).name() << endl;
    cout << typeid(arr).name() << endl;
    cout << typeid(d).name() << endl;
    cout << typeid(a).name() << endl;
    cout << typeid(*a).name() << endl;
    cout << typeid(std::string).name() << endl;
    

    return 0;
}
