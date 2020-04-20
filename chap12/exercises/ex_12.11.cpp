//练习 12.11：如果我们像下面这样调用 process，会发生什么？
// process(shared_ptr<int>(p.get()));

/*
* 利用 p.get() 获得内置指针然后创建一个临时 shared_ptr 变量来初始化形参。这个临时的 shared_ptr 由于是使用内置指针创建的，所以与 p 是相互独立的，
* 所以此时 p 的引用奇数还是 1，临时变量的引用奇数也是 1，然后赋值给形参，这个临时变量的引用奇数变为 2。
* 接着临时变量被销毁，所以 形参局部变量的引用奇数变为 1。当 process 函数执行完毕，局部变量被销毁，引用奇数变为 0，指针指向的内存被释放。
* 此时 p 管理的指针变为空悬指针，接下来不能再释放或者解引用 p 了（再次释放则会发生错误，解引用得到的值是未定义的）。
*/



#include <iostream>
#include <memory>

using std::shared_ptr;

void process(shared_ptr<int> ptr) {
    //...
    std::cout << ptr.use_count() << std::endl;
}

int main() {
    shared_ptr<int> p(new int(42));

    //process(shared_ptr<int>(p));
    process(shared_ptr<int>(p.get()));

    std::cout << p.use_count() << std::endl;

    std::cout << *p << std::endl;

    return 0;
}
