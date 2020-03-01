//练习 7.19：在你的 Person 类中，你将把哪些成员声明成 public 的？哪些声明成 private 的？解释你这样做的原因。

#include <iostream>
#include <string>

class Person {
   private:
    std::string name;
    std::string address;

   public:
    Person() = default;
    Person(const std::string &n, const std::string &a) : name(n), address(a) {}

    std::string getName() const { return name; }
    std::string getAddress() const { return address; }
};

/*
* 原因：出于封装考虑。
*/
