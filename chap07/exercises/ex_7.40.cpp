//练习 7.40：从下面的抽象概念中选择一个（或者你自己指定一个），思考这样的类需要哪些数据成员，
//提供一组合理的构造函数并阐明这样做的原因。
// (a) Book     (b) Date        (c) Employee
// (d) Vehicle  (e) Object      (f) Tree
#include <string>

class Book {
   private:
    std::string title;
    std::string author;
    unsigned pages;
    double price;
    unsigned edition;

   public:
    Book(std::string t, std::string a, unsigned p, double pr, unsigned e = 1) : title(t), author(a), price(pr), edition(e) {}
};

/*
* 对于一本书来说，除了 edition 可以有默认值以外其它所有数据成员必须提供实参。
*/
