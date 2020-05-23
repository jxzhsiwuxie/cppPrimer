#ifndef JXZ_BULK_QUOTE_H_
#define JXZ_BULK_QUOTE_H_

#include "Disc_quote.h"

class Bulk_quote : public Disc_quote {
   public:
    Bulk_quote() = default;
    Bulk_quote(const std::string &, double, std::size_t, double);
    ~Bulk_quote() = default;

    //覆盖基类的函数版本以实现基于大量购买的折扣政策
    double net_price(std::size_t) const override;
};

Bulk_quote::Bulk_quote(const std::string &book, double p, std::size_t n, double disc) : Disc_quote(book, p, n, disc) {}

double Bulk_quote::net_price(std::size_t cnt) const {
    if (cnt >= quatity)
        return cnt * (1 - discount) * price;
    return cnt * price;
}

#endif