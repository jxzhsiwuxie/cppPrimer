//练习 13.5：给定下面的类框架，编写一个拷贝构造函数，拷贝所有成员。你的拷贝构造函数应该动态分配一个新的 string（参加 12.1.2 节，第 407 页），
//并将对象拷贝到 ps 指向的位置，而不是拷贝 ps 本身：
// class HasPtr {
// public:
//     HasPtr(const std::string &s = std::string()):
//         ps(new std::string(s)), i(0) {}
// private:
//     std::string *ps;
//     int i;
// };

#include <iostream>
#include <string>

class HasPtr {
   public:
    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
    HasPtr(const HasPtr &rhs) : ps(new std::string(*rhs.ps)), i(rhs.i) {}
    // HasPtr(const HasPtr &rhs) : ps(rhs.ps), i(rhs.i) {}

    std::string getString() const { return *ps; }
    void updateString(const char *ch) { ps->append(ch); }

   private:
    std::string *ps;
    int i;
};

int main() {
    HasPtr obj1("abc");
    HasPtr obj2(obj1);

    std::cout << "原始情况 obj1 内容为：" << obj1.getString() << std::endl;
    std::cout << "原始情况 obj2 内容为：" << obj2.getString() << std::endl;

    obj1.updateString("a");
    std::cout << "obj1 被改变后 obj1 内容为：" << obj1.getString() << std::endl;
    std::cout << "obj1 被改变后 obj2 内容为：" << obj2.getString() << std::endl;

    return 0;
}
