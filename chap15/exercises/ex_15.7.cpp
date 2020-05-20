//练习 15.7：定义一个类使其实现一种数量受限的折扣策略，具体策略是：当购买书籍的数量不超过一个给定的限量时享受折扣，
//如果购买量一旦超过了限量，则超出的部分将以原价销售。

#include "Quote.h"
#include "Limit_quote.h"

int main(){

    Quote quote("c++ primer", 99.99);
    Limit_quote bulkQuote("c++ primer plus", 88.99, 101, 0.9);

    print_total(std::cout, quote, 100);
    print_total(std::cout, bulkQuote, 100);
    print_total(std::cout, bulkQuote, 200);

    return 0;
}
