//练习 7.9：对于 7.1.2 节（第 233 页）练习中的代码，添加读取和打印 Person 对象的操作。

#include <iostream>
#include <string>

struct Person {
    std::string name;
    std::string address;

    std::string getName() const { return name; }
    std::string getAddress() const { return address; }
};

std::istream &read(std::istream &, Person &);
std::ostream &print(std::ostream &, const Person &);

std::istream &read(std::istream &is, Person &item) {
    is >> item.name >> item.address;

    return is;
}

std::ostream &print(std::ostream &os, const Person &item) {
    os << "姓名：" << item.getName() << "，住址：" << item.getAddress();

    return os;
}
