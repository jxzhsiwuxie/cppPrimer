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
};

Quote::Quote() {
}

Quote::~Quote() {
}

#endif