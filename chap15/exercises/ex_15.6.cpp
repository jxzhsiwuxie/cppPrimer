//练习 15.6：将 Quote 和 Bulk_quote 对象传给 15.2.1 节（第 529 页）练习中的 print_total 函数，检查该函数是否正确。

#include "Quote.h"
#include "Bulk_quote.h"

int main(){

    Quote quote("c++ primer", 99.99);
    Bulk_quote bulkQuote("c++ primer plus", 88.99, 10, 0.2);

    print_total(std::cout, quote, 100);
    print_total(std::cout, bulkQuote, 100);

    return 0;
}
