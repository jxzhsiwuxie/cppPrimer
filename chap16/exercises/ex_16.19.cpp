//练习 16.19：编写函数，接受一个容器的引用，打印容器中的元素。使用元素的 size_type 和 size 成员来控制打印元素的循环。

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

template <typename T>
void printContainer(T &container) {
    typename T::size_type i;
    for (i = 0; i != container.size(); ++i)
        cout << container[i] << " ";
    cout << endl;
}

int main() {
    string str = "dadsdasdsadda";
    vector<int> ivec = {1, 2, 3, 4, 5, 6, 7, 8};

    printContainer(str);
    printContainer(ivec);

    return 0;
}