//练习 15.11：为你的 Quote 类体系添加一个名为 debug 的虚函数，令其分别显式每个类的数据成员。

#include "Quote.h"
#include "Bulk_quote.h"

int main(){
    Quote q("isbn-0000-1111", 20.0);
    Quote *q1 = new Bulk_quote("isbn-1111-1111", 10.0, 20, 0.5);

    q.debug();
    q1->debug();


    return 0;
}
