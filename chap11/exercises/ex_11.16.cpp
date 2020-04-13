//练习 11.16：使用一个 map 迭代器编写一个表达式，将一个值赋予一个元素。

#include <cstddef>
#include <iostream>
#include <map>
#include <string>

using std::cout;
using std::endl;
using std::map;
using std::size_t;
using std::string;

int main() {
    map<string, size_t> people = {{"zhangsan", 30}};
    map<string, size_t>::iterator it = people.begin();
    while (it != people.end()){
        cout << it->first << ", " << it->second << endl;
        ++it;
    }

    auto beg = people.begin();
    beg->second = 24;
    while (beg != people.end()){
        cout << beg->first << ", " << beg->second << endl;
        ++beg;
    }

    return 0;
}
