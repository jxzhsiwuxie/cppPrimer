//练习 9.33：在本节最后一个例子中，如果不将 insert 的结果赋予 begin，将会发生什么？
//编写程序，去掉此语句，验证你的答案。

/*
* 对于 vector，在插入新元素之后，如果存储空间被重新分配了，则指向容器的迭代器、指针和引用都会失效。
* 这样循环的终止条件可能永远无法满足。
*/

#include <ctime>
#include <iostream>
#include <random>
#include <vector>

using std::default_random_engine;
using std::uniform_int_distribution;

using std::cout;
using std::endl;
using std::vector;

int main() {
    default_random_engine e(std::time(NULL));
    uniform_int_distribution<int> u(10, 100);

    //处理容器中的每个元素，在其后添加一个新元素。
    //跳过新加的元素，只处理原有的元素。
    vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << "初始时 vector 包含元素：" << endl;
    for (auto s : v)
        cout << s << " ";
    cout << endl;

    auto begin = v.begin();
    while (begin != v.end()) {
        //做一些处理
        //...
        ++begin;
        //插入新值
        // begin = v.insert(begin, u(e));
        v.insert(begin, u(e));  //使用这一句则程序进入死循环。
        ++begin;
    }

    cout << "一顿操作之后 vector 包含元素：" << endl;
    for (auto s : v)
        cout << s << " ";
    cout << endl;

    return 0;
}
