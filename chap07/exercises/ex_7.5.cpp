//练习 7.5：在你的 Person 类中提供一些操作使其能够返回姓名和住址。这些函数是否应该是 const 的呢？解释原因。

#include <string>

struct Person {
    std::string name;
    std::string address;

    std::string getName() const { return name; }
    std::string getAddress() const { return address; }
};

/*
* 新增的两个成员函数应该是 const 的，因为它不需要改变调用的 Person 对象。
*/
