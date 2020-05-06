//练习 14.12：你在 7.5.1 节的练习 7.40（第 261 页）中曾经选择并编写了一个类，为它编写一个输入运算符，并确保它可以处理输入错误。

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