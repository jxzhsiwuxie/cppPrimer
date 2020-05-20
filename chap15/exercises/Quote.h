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

double print_total(std::ostream &os, const Quote &item, std::size_t n) {
    //根据传入的 item 形参的对象类型
    //调用 Quote::net_price 或者 Bulk_Quote::net_price
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << std::endl;

    return ret;
}

#endif