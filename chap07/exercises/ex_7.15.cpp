//练习 7.15：为你的 Person 类添加正确的构造函数。

#include <iostream>
#include <string>

struct Person {
    std::string name;
    std::string address;

    //构造函数
    Person() = default;
    Person(const std::string &n, const std::string &a) : name(n), address(a) {}

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
