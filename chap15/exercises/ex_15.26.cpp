//练习 15.26：定义 Quote 和 Bulk_quote 的拷贝控制成员，令其与合成的版本行为一致。为这些成员以及其它构造函数添加打印状态的语句，
//使得我们能够知道正在运行哪个程序。使用这些类编写程序，预测程序创建和销毁哪些对象。重复实验，不断比较你的预测和实际结果是否相同，
//直到预测完全准确再结束。

#include "Bulk_quote.h"
#include "Disc_quote.h"
#include "Quote.h"

int main() {
    Quote quote0("isbn-000-000", 9.99);
    Quote quote1(quote0);
    Quote quote2 = quote0;
    quote2 = quote1;

    Quote quote3(std::move(quote0));
    Quote quote4;
    quote4 = Quote("isbn-000-002", 9.99);

    std::cout << "---------------------------------------" << std::endl;
    Bulk_quote bulkQuote0("isbn-111-000", 19.99, 100, 0.5);
    Bulk_quote bulkQuote1(bulkQuote0);
    Bulk_quote bulkQuote2 = bulkQuote0;
    bulkQuote2 = bulkQuote1;

    Bulk_quote bulkQuote3(std::move(bulkQuote0));
    Bulk_quote bulkQuote4;
    bulkQuote4 = std::move(bulkQuote0);

    return 0;
}
