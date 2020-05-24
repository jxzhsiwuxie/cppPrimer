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

    //拷贝构造
    Disc_quote(const Disc_quote& item) : Quote(item), quatity(item.quatity), discount(item.discount) {
        std::cout << "Disc_quote copy constructor" << std::endl;
    }
    //移动构造
    Disc_quote(Disc_quote&& item) : Quote(std::move(item)), quatity(item.quatity), discount(item.discount) {
        std::cout << "Disc_quote move constructor" << std::endl;
    }
    //拷贝赋值
    Disc_quote& operator=(const Disc_quote& rhs) {
        std::cout << "Disc_quote copy assignmen" << std::endl;
        Quote::operator=(rhs);
        quatity = rhs.quatity;
        discount = rhs.discount;

        return *this;
    }
    //移动赋值
    Disc_quote& operator=(Disc_quote&& rhs) {
        std::cout << "Disc_quote move assignmen" << std::endl;
        Quote::operator=(std::move(rhs));
        quatity = rhs.quatity;
        discount = rhs.discount;

        return *this;
    }
};

#endif