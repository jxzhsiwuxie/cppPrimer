#ifndef JXZ_LIMIT_QUOTE_H_
#define JXZ_LIMIT_QUOTE_H_

#include "Disc_quote.h"

class Limit_quote : public Disc_quote {
   private:
    std::size_t limitNum;
    double discount;

   public:
    Limit_quote() = default;
    ~Limit_quote() = default;
    Limit_quote(const std::string &book, double p, std::size_t lim, double disc) : Disc_quote(book, p, lim, disc) {}

    double net_price(std::size_t cnt) const override {
        if (cnt < limitNum)
            return cnt * (1 - discount) * price;
        return (cnt - limitNum * discount) * price;
    }
};

#endif