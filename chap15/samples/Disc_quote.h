#ifndef JXZ_DISC_QUOTE_H_
#define JXZ_DISC_QUOTE_H_

#include "Quote.h"

class Disc_quote : public Quote {
   protected:
    std::size_t quatity = 0;  //折扣适用的购买量
    double discount = 0.0;    //表示折扣的小数值
   public:
    Disc_quote() = default;
    Disc_quote(const std::string& book, double price, std::size_t qty, double disc) : Quote(book, price), quatity(qty), discount(disc) {}
    double net_price(std::size_t) const = 0;
};

#endif