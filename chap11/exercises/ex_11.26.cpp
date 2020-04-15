//练习 11.26：可以用什么类型来对 map 进行下标操作？下标运算符返回的类型是什么？
//请给出一个具体例子————即，定义一个 map，然后写出一个可以用来对 map 进行下标操作的类型以及下标运算符将会返回的类型。

/*
* 可以用 map 的 key_type 类型来对 map 进行下标操作，下标操作返回的类型是 map 对应的 mapped_type。
*/

#include <map>
#include <string>
#include <cstddef>
#include <iostream>

using std::string;
using std::map;
using std::size_t;

int main(){
    map<string, size_t> m;
    map<string, size_t>::key_type name = "zhangsan";
    map<string, size_t>::mapped_type age = 24;

    m[name] = age;

    std::cout << m.at(name) << std::endl;

    return 0;
}



