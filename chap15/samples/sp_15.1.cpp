//Quote 表示按原价销售的书籍
//Bulk_Quote 表示可以打折销售的书籍

#include <cstddef>
#include <iostream>
#include <string>

class Quote {
   private:
   public:
    std::string isbn() const;
    virtual double net_price(std::size_t n) const;
};

class Bulk_Quote : public Quote {
   private:
   public:
    double net_price(const std::size_t n) const override;
};

double print_total(std::ostream &os, const Quote &item, std::size_t n) {
    //根据传入的 item 形参的对象类型
    //调用 Quote::net_price 或者 Bulk_Quote::net_price
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << std::endl;

    return ret;
}
