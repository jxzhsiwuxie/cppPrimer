//练习 16.38：当我们调用 make_shared（参见 12.1.1 节，第 401 页）时，必须提供一个显示模板实参。
//解释为什么需要显式模板实参以及它是如何使用的。

/*
* std::make_shared<T> (args)
* args 初始化相应类型的参数，从这个参数不一定能推断出想要构造的对象的类型，
* 必须通过显式模板实参来指定。
*/

#include <memory>

int main() {
    std::shared_ptr<int> iptr = std::make_shared<int>(10);
    return 0;
}
