#ifndef JXZ_LIMIT_QUOTE_H_
#define JXZ_LIMIT_QUOTE_H_

#include "Quote.h"

class Limit_quote : public Quote {
   private:
    std::size_t limitNum;
    double discount;

   public:
    Limit_quote() = default;
    ~Limit_quote() = default;
    Limit_quote(const std::string &book, double p, std::size_t lim, double disc) : Quote(book, p), limitNum(lim), discount(disc) {}

    double net_price(std::size_t cnt) const override {
        if (cnt < limitNum)
            return cnt * (1 - discount) * price;
        return (cnt - limitNum * discount) * price;
    }
};

#endif