//练习 11.25：对比下面程序与上一题程序。
// vector<int> v;
// v[0] = 1;

/*
* 此时的 v 是空的，所以下标访问的行为是不确定的。
*/

#include <vector>
#include <iostream>

int main(){
    std::vector<int> v;
    v[0] = 1;

    std::cout << v.at(0) << std::endl;

    return 0;
}
