//练习 9.20：编写程序，从一个 list<int> 拷贝元素到两个 deque 中。值为偶数的所有元素都拷贝到一个 deque 中，而奇数值元素都拷贝到另一个 deque 中。

#include <ctime>
#include <deque>
#include <iostream>
#include <list>
#include <random>
#include <string>

using std::cin;
using std::cout;
using std::deque;
using std::endl;
using std::list;
using std::string;

int main() {
    std::uniform_int_distribution<int> u(-100, 100);
    std::default_random_engine e(std::time(NULL));

    list<int> total;

    for (int i = 0; i < 20; ++i)
        total.push_back(u(e));

    cout << "原始的 list 元素为：" << endl;
    for (auto n : total)
        cout << n << " ";
    cout << endl;

    deque<int> oddDeque, evenDeque;
    auto beg = total.cbegin(), end = total.cend();
    while (beg != end) {
        *beg % 2 == 0 ? evenDeque.push_back(*beg) : oddDeque.push_back(*beg);
        ++beg;
    }

    cout << "经过分组后，oddDeque 中的元素为：" << endl;
    for (auto n : oddDeque)
        cout << n << " ";
    cout << endl;

    cout << "经过分组后，evenDeque 中的元素为：" << endl;
    for (auto n : evenDeque)
        cout << n << " ";
    cout << endl;

    return 0;
}
