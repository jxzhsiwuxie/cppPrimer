#ifndef JXZ_BULK_QUOTE_H_
#define JXZ_BULK_QUOTE_H_

#include "Quote.h"

class Bulk_quote : public Quote {
   private:
    std::size_t min_qty = 0;  //适用折扣信息的最低购买量
    double discount = 0.0;    //以小数表示的折扣额
   public:
    Bulk_quote() = default;
    Bulk_quote(const std::string &, double, std::size_t, double);
    ~Bulk_quote() = default;

    //覆盖基类的函数版本以实现基于大量购买的折扣政策
    double net_price(std::size_t) const override;
};

Bulk_quote::Bulk_quote(const std::string &book, double p, std::size_t n, double disc) : Quote(book, p), min_qty(n), discount(disc) {}

double Bulk_quote::net_price(std::size_t cnt) const {
    if (cnt >= min_qty)
        return cnt * (1 - discount) * price;
    return cnt * price;
}

#endif