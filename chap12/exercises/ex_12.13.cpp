//练习 12.13：如果执行下面的代码，会发生什么？
// auto sp = make_shared<int>();
// auto p = sp.get();
// delete p;

/*
* 执行完毕这段代码后，智能指针 sp 管理的指针指向的内存已经被释放了，但是此时 sp 的引用计数还是 1，
* 此时如果 sp 被销毁则会导致重复释放一个内存，发生错误；
* 如果解引用 sp 则得到的值是未定义的（实际测试是得不到值的）。
*/

#include <iostream>
#include <memory>

using std::make_shared;
using std::shared_ptr;

int main() {
    auto sp = make_shared<int>();
    {
        auto p = sp.get();
        delete p;
        auto ssp = sp;
    }

    std::cout << "此时 sp 的引用计数为：" << sp.use_count() << std::endl;
    std::cout << "此时解引用 sp 得到的值为：" << *sp << std::endl;

    return 0;
}
