#ifndef JXZ_QUOTE_H_
#define JXZ_QUOTE_H_

#include <cstddef>
#include <iostream>
#include <string>

class Quote {
   private:
    std::string bookNo;  //书籍的 ISBN 编号

   protected:
    double price = 0.0;  //代表普通状态下打折的价格

   public:
    Quote() = default;
    virtual ~Quote() = default;  //对析构函数进行动态绑定
    Quote(const std::string &book, double sales_price) : bookNo(book), price(sales_price) {}
    std::string isbn() const { return bookNo; }
    virtual double net_price(std::size_t n) const { return n * price; }

    //拷贝构造
    Quote(const Quote &item) : bookNo(item.bookNo), price(item.price) {
        std::cout << "Quote copy constructor" << std::endl;
    }
    //移动构造
    Quote(Quote &&item) : bookNo(item.bookNo), price(item.price) {
        std::cout << "Quote move constructor" << std::endl;
    }
    //拷贝赋值
    Quote &operator=(const Quote &rhs) {
        std::cout << "Quote copy assignmen" << std::endl;
        bookNo = rhs.bookNo;
        price = rhs.price;
        return *this;
    }
    //移动赋值
    Quote &operator=(const Quote &&rhs) {
        std::cout << "Quote move assignmen" << std::endl;
        bookNo = rhs.bookNo;
        price = rhs.price;
        return *this;
    }

    virtual void debug() const {
        std::cout << "bookNo = " << bookNo << "; price = " << price << std::endl;
    }

    virtual Quote *clone() const & {
        return new Quote(*this);
    }

    virtual Quote *clone() && {
        return new Quote(std::move(*this));
    }
};

double print_total(std::ostream &os, const Quote &item, std::size_t n) {
    //根据传入的 item 形参的对象类型
    //调用 Quote::net_price 或者 Bulk_Quote::net_price
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << std::endl;

    return ret;
}

#endif