//练习 9.34：假定 vi 是一个保存 int 的容器，其中有偶数值也有奇数值，分析下面的循环的行为，
//然后编写程序验证你的分析是否正确。
// iter = vi.begin();
// while (iter != vi.end())
//     if(*iter % 2)
//         iter = vi.insert(iter, *iter);
//     ++iter;

/*
* 题中似乎少了一个大括号。
* 在补上大括号的前提下，程序似乎是希望将容器中的奇数元素都复制一遍，但是，
* insert 返回的迭代器是指向新添加的元素的，所以当第一次 *iter%2 不为 0 的时候，
* 循环就会一直向容器中插入这个值，程序进入死循环。
* 正确的做法是在插入之后需要将 iter 向前移动两位使其指向下一个元素。
*/

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main() {
    vector<int> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << "初始时 vector 包含元素：" << endl;
    for (auto s : vi)
        cout << s << " ";
    cout << endl;

    auto iter = vi.begin();
    while (iter != vi.end()) {
        if (*iter % 2) {
            iter = vi.insert(iter, *iter);
            ++iter;
        }
        ++iter;
    }

    cout << "一顿操作后 vector 包含元素：" << endl;
    for (auto s : vi)
        cout << s << " ";
    cout << endl;

    return 0;
}
