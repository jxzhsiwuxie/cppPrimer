//练习 15.30：编写你自己的 Basket 类，用它计算上一个练习中交易记录总价格。

#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "Basket.h"
#include "Bulk_quote.h"
#include "Quote.h"

using std::cout;
using std::endl;
using std::make_shared;
using std::shared_ptr;
using std::string;
using std::vector;

int main() {
    vector<shared_ptr<Quote>> quoteVector;
    quoteVector.push_back(make_shared<Bulk_quote>("isbn-000-000", 9.99, 10, 0.9));
    quoteVector.push_back(make_shared<Bulk_quote>("isbn-000-001", 9.99, 10, 0.9));
    quoteVector.push_back(make_shared<Bulk_quote>("isbn-000-002", 9.99, 10, 0.9));
    quoteVector.push_back(make_shared<Bulk_quote>("isbn-000-003", 9.99, 10, 0.9));
    quoteVector.push_back(make_shared<Bulk_quote>("isbn-000-004", 9.99, 10, 0.9));

    double total = 0.0;
    for (const auto &item : quoteVector)
        total += item->net_price(100);
    cout << "总的 net_price 为：" << total << endl;

    Basket basket;
    Bulk_quote bulkQuote0("isbn-000-000", 9.99, 10, 0.9);
    Bulk_quote bulkQuote1("isbn-000-001", 9.99, 10, 0.9);
    Bulk_quote bulkQuote2("isbn-000-002", 9.99, 10, 0.9);
    Bulk_quote bulkQuote3("isbn-000-003", 9.99, 10, 0.9);
    Bulk_quote bulkQuote4("isbn-000-004", 9.99, 10, 0.9);
    for (auto i = 0; i < 100; ++i)
        basket.add_item(bulkQuote0);
    for (auto i = 0; i < 100; ++i)
        basket.add_item(bulkQuote1);
    for (auto i = 0; i < 100; ++i)
        basket.add_item(bulkQuote2);
    for (auto i = 0; i < 100; ++i)
        basket.add_item(bulkQuote3);
    for (auto i = 0; i < 100; ++i)
        basket.add_item(bulkQuote4);

    basket.total_receipt(cout);

    return 0;
}
