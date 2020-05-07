//练习 14.17：你在 7.5.1 节的练习 7.40（第 261 页）中曾经选择并编写了一个类，你认为它应该含有相等运算符么？
//如果是，请实现它们；如果不是，请解释原因。

#include <iostream>
#include <string>

class Book {
    friend std::ostream &operator<<(std::ostream &, const Book &);
    friend std::istream &operator>>(std::istream &, Book &);
    friend bool operator==(const Book &, const Book &);
    friend bool operator!=(const Book &, const Book &);

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

bool operator==(const Book &lhs, const Book &rhs) {
    return lhs.author == rhs.author &&
           lhs.edition == rhs.edition &&
           lhs.pages == rhs.pages &&
           lhs.price == rhs.price &&
           lhs.title == rhs.title;
}

bool operator!=(const Book &lhs, const Book &rhs) {
    return !(lhs == rhs);
}
