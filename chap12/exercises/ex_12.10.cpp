//练习 12.10：下面的代码中调用了第 413 页中定义的 process 函数，解释此调用是否正确。如果不正确，应该如何修改？
// shared_ptr<int> p(new int(42));
// process(shared_ptr<int>(p));

/*
* 正确。
* shared_ptr<int> p(new int(42));   //引用奇数为 1
* process(shared_ptr<int>(p));      //利用 p 创建了了一个临时的 shared_ptr，使得引用奇数变为 2，
* 然后将这个临时 shared_ptr 赋值给形参，引用奇数变为 3。
* process 形参赋值完毕后，临时变量被释放，引用奇数变为 2，执行完毕后局部变量被销毁，引用奇数变为 1
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
    process(shared_ptr<int>(p));

    std::cout << p.use_count() << std::endl;

    std::cout << *p << std::endl;

    return 0;
}
