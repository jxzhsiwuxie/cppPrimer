#ifndef JXZ_BASKET_H_
#define JXZ_BASKET_H_

#include <iostream>
#include <memory>
#include <set>

#include "Bulk_quote.h"

class Basket {
   private:
    //该函数用于比较 shared_ptr，multiset 成员会用到
    static bool compare(const std::shared_ptr<Quote> &lhs, const std::shared_ptr<Quote> &rhs) {
        return lhs->isbn() < rhs->isbn();
    }
    //multiset 保存多个报价，按照 compare 成员排序
    std::multiset<std::shared_ptr<Quote>, decltype(compare) *> items{compare};

   public:
    //Basket 使用合成的默认构造函数和拷贝控制成员
    void add_item(const Quote &sale) {  //拷贝给定的对象
        items.insert(std::shared_ptr<Quote>(sale.clone()));
    }
    void add_item(Quote &&sale) {  //移动给定的对象
        items.insert(std::shared_ptr<Quote>(std::move(sale).clone()));
    }
    //打印每本书的总价和购物篮中所有书的总价
    double total_receipt(std::ostream &) const;
};

double Basket::total_receipt(std::ostream &os) const {
    double sum = 0.0;  //保存实时计算出的总价格
    //iter 指向 ISBN 相同的一批元素中的第一个
    //upper_bound 返回一个迭代器，该迭代器指向这批元素的尾后位置
    for (auto iter = items.cbegin(); iter != items.cend(); iter = items.upper_bound(*iter)) {
        sum += print_total(os, **iter, items.count(*iter));
    }
    os << "总的价格为：" << sum << std::endl;
    return sum;
}

#endif