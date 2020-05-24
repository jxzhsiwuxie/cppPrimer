//练习 15.29：再运行一次你的程序，这次传入 Quote 对象的 share_ptr。如果这次计算出的总额与之前的不一致，
//解释为什么；如果一致，也请说明原因。


#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include "Bulk_quote.h"
#include "Quote.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::shared_ptr;
using std::make_shared;

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

    return 0;
}

/*
* 结果不一样。
* 在向 vector<Quote> 中添加 Bulk_quote 对象时，容器只会拷贝其中基类的部分，调用的 net_price 也是基类的函数。
* 向 vector<shared_ptr<Quote>> 添加元素时，添加的是 shared_ptr<Bulk_quote>，但是可以转换成 shared_ptr<Quote>，
* 调用的是 Bulk_quote 的 net_price 函数。
*/
