//练习 15.28：定义一个存放 Quote 的 vector，将 Bulk_quote 对象传入其中。
//计算 vector 中所有元素总的 net_price。

#include <iostream>
#include <string>
#include <vector>

#include "Bulk_quote.h"
#include "Quote.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
    vector<Quote> quoteVector;
    Bulk_quote bulkQuote0("isbn-000-000", 9.99, 10, 0.9);
    Bulk_quote bulkQuote1("isbn-000-001", 9.99, 10, 0.9);
    Bulk_quote bulkQuote2("isbn-000-002", 9.99, 10, 0.9);
    Bulk_quote bulkQuote3("isbn-000-003", 9.99, 10, 0.9);
    Bulk_quote bulkQuote4("isbn-000-004", 9.99, 10, 0.9);
    quoteVector.push_back(bulkQuote0);
    quoteVector.push_back(bulkQuote1);
    quoteVector.push_back(bulkQuote2);
    quoteVector.push_back(bulkQuote3);
    quoteVector.push_back(bulkQuote4);

    double total = 0.0;
    for (const auto &item : quoteVector)
        total += item.net_price(100);

    cout << "总的 net_price 为：" << total << endl;

    return 0;
}
