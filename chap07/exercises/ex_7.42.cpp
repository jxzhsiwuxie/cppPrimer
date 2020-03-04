//练习 7.42：对于你在练习 7.40（参见 7.5.1 节，第 261 页）中编写的类，确定哪些构造函数可以使用委托。
//如果可以的话，编写委托构造函数。如果不可以，从抽象概念列表中重新选择一个你认为可以使用委托构造函数的，为挑选出的这个概念编写类定义。

#include <string>

class Book {
   private:
    std::string title;
    std::string author;
    unsigned pages;
    double price;
    unsigned edition;

   public:
    Book(std::string t, std::string a, unsigned p, double pr, unsigned e) : title(t), author(a), price(pr), edition(e) {}
    Book(std::string t, std::string a, unsigned p, double pr) : Book(t, a, p, 1) {}
};
