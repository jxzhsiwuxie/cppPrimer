#ifndef JXZ_BULK_QUOTE_H_
#define JXZ_BULK_QUOTE_H_

#include "Disc_quote.h"

class Bulk_quote : public Disc_quote {
   public:
    Bulk_quote() = default;
    Bulk_quote(const std::string&, double, std::size_t, double);
    ~Bulk_quote() = default;

    //覆盖基类的函数版本以实现基于大量购买的折扣政策
    double net_price(std::size_t) const override;

    //拷贝构造
    Bulk_quote(const Bulk_quote& item) : Disc_quote(item) {
        std::cout << "Bulk_quote copy constructor" << std::endl;
    }
    //移动构造
    Bulk_quote(Bulk_quote&& item) : Disc_quote(std::move(item)) {
        std::cout << "Bulk_quote move constructor" << std::endl;
    }
    //拷贝赋值
    Bulk_quote& operator=(const Bulk_quote& rhs) {
        std::cout << "Bulk_quote copy assignmen" << std::endl;
        Disc_quote::operator=(rhs);

        return *this;
    }
    //移动赋值
    Bulk_quote& operator=(Bulk_quote&& rhs) {
        std::cout << "Bulk_quote move assignmen" << std::endl;
        Disc_quote::operator=(std::move(rhs));

        return *this;
    }
};

Bulk_quote::Bulk_quote(const std::string& book, double p, std::size_t n, double disc) : Disc_quote(book, p, n, disc) {}

double Bulk_quote::net_price(std::size_t cnt) const {
    if (cnt >= quatity)
        return cnt * (1 - discount) * price;
    return cnt * price;
}

#endif