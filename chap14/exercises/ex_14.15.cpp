//练习 14.15：你在 7.5.1 节的练习 7.40（第 261 页）中曾经选择并编写了一个类，你认为它应该含有其它算术运算符么？
//如果是，请实现它们；如果不是，请解释原因。


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
    Book() = default;
    Book(std::string t, std::string a, unsigned p, double pr, unsigned e = 1) : title(t), author(a), price(pr), edition(e) {}

    Book &operator=(const Book &);
};

std::ostream &operator<<(std::ostream &os, const Book &book) {
    os << book.author << " " << book.title;
    return os;
}

std::istream &operator>>(std::istream &is, Book &book) {
    is >> book.author >> book.title >> book.edition >> book.pages >> book.price;
    if (!is) {
        book = Book();
    }

    return is;
}

/*
* 不需要包含其它算术运算符了，对于 Book 而言，加减乘除的运算没有实际的意义。
*/
