//练习 7.22：修改你的 Person 类使其隐藏实现细节。

#include <iostream>
#include <string>

class Person {
    friend std::istream &read(std::istream &, Person &);
    friend std::ostream &print(std::ostream &, const Person &);

   private:
    std::string name;
    std::string address;

   public:
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
