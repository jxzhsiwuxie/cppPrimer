//练习 14.5：在 7.5.1 节的练习题 7.40（第 261 页中），编写了下列类中某一个的框架，
//请问在这个类中应该定义重载的运算符么？如果是，请写出来。
// (a) Book     (b) Date        (c) Employee
// (d) Vehicle  (e) Object      (f) Tree

#include <iostream>
#include <string>

class Book {
    friend std::ostream &operator<<(std::ostream &, const Book &);
    friend std::istream &operator>>(std::istream &, Book &);

   private:
    std::string title;
    std::string author;
    unsigned pages;
    double price;
    unsigned edition;

   public:
    Book(std::string t, std::string a, unsigned p, double pr, unsigned e = 1) : title(t), author(a), price(pr), edition(e) {}

    Book &operator=(const Book &);
};
