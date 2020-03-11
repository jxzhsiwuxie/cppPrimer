//练习 9.26：使用下面代码定义的 ia，将 ia 拷贝到一个 vector 和一个 list 中。使用单迭代器版本的 erase 从 list 中
//删除奇数元素，从 vector 中删除偶数元素。
// int ia[] = {0,1,1,2,3,5,8,13,21,55,89};

#include <iostream>
#include <iterator>
#include <list>
#include <vector>

using std::cout;
using std::endl;
using std::list;
using std::vector;

int main() {
    int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
    vector<int> iVector(std::begin(ia), std::end(ia));
    list<int> iList(std::begin(ia), std::end(ia));

    cout << "初始时 vector 中的元素为：" << endl;
    for (auto n : iVector)
        cout << n << " ";
    cout << endl;

    cout << "初始时 list 中的元素为：" << endl;
    for (auto n : iList)
        cout << n << " ";
    cout << endl;

    auto vBegin = iVector.begin();
    auto lBegin = iList.begin();

    while (vBegin != iVector.end()) {
        if (*vBegin % 2) {
            ++vBegin;
        } else {
            vBegin = iVector.erase(vBegin);
        }
    }

    while (lBegin != iList.end()) {
        if (*lBegin % 2) {
            lBegin = iList.erase(lBegin);
        } else {
            ++lBegin;
        }
    }

    cout << "最终 vector 中的元素为：" << endl;
    for (auto n : iVector)
        cout << n << " ";
    cout << endl;

    cout << "最终 list 中的元素为：" << endl;
    for (auto n : iList)
        cout << n << " ";
    cout << endl;

    return 0;
}
