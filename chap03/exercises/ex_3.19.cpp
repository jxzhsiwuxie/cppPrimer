//练习 3.19：如果想定义一个含有 10 个元素的 vector 对象，所有元素的值都是 42，
//请列举出三种不同的实现方法。哪种方法更好呢？为什么？

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
    //列表初始化方法
    vector<int> ivec1{42, 42, 42, 42, 42, 42, 42, 42, 42, 42};

    //直接构造的方法
    vector<int> ivec2(10, 42);

    //动态添加的方法
    vector<int> ivec3;
    for (int i = 0; i < 10; i++)
        ivec3.push_back(42);

    return 0;
}

/*
* 对于当前问题来说第二种方法最好。
* 初始化的时候 vector 对象的容量已知并且每个元素的值都相同，使用直接构造的方法简单方便。
*/
