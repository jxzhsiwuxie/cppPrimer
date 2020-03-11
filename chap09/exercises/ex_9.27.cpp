//练习 9.27：编写程序，查找并删除 forwars_list 中的奇数元素。

#include <ctime>
#include <forward_list>
#include <iostream>
#include <random>

using std::cout;
using std::default_random_engine;
using std::endl;
using std::forward_list;
using std::uniform_int_distribution;

int main() {
    default_random_engine e(std::time(NULL));
    uniform_int_distribution<int> u(-64, 64);

    forward_list<int> flst{u(e)};
    auto fBegin = flst.begin();
    for (int i = 0; i < 20; ++i)
        fBegin = flst.insert_after(fBegin, u(e));

    cout << "初始时 forward_list 包含元素：" << endl;
    for (auto n : flst)
        cout << n << " ";
    cout << endl;

    auto prev = flst.before_begin();
    auto curr = flst.begin();
    while (curr != flst.end()) {
        if (*curr % 2)
            curr = flst.erase_after(prev);
        else {
            prev = curr;
            ++curr;
        }
    }

    cout << "最终 forward_list 包含元素：" << endl;
    for (auto n : flst)
        cout << n << " ";
    cout << endl;

    return 0;
}
