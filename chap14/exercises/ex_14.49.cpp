//练习 14.49：为上一题提到的类定义一个转换目标是 bool 的类型转换运算符，先不用在一这么做是否应该。

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
    Book &operator=(const Book &&) noexcept;

    explicit operator bool() const { return !title.empty(); }
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

Book &Book::operator=(const Book &book) {
    title = book.title;
    author = book.author;
    pages = book.pages;
    price = book.price;
    edition = book.edition;
}

Book &Book::operator=(const Book &&book) noexcept {
    title = book.title;
    author = book.author;
    pages = book.pages;
    price = book.price;
    edition = book.edition;
}