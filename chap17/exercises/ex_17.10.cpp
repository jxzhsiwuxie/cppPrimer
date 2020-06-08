//练习 17.10：使用序列 1、2、3、5、8、13、21 初始化一个 bitset，将这些位置置位。对另一个 bitset 进行默认你初始化，并编写一小段程序将其恰当的位置置位。

#include <bitset>
#include <iostream>
#include <string>

using std::bitset;
using std::cout;
using std::endl;
using std::string;

int main() {
    string bstr("1000000010000100101110");
    bitset<24> bts1(bstr);

    bitset<24> bts2;
    bts2.flip(1);
    bts2.flip(2);
    bts2.flip(3);
    bts2.flip(5);
    bts2.set(8, 1);
    bts2.set(13, 1);
    bts2.set(21, 1);

    cout << bts1 << endl;
    cout << bts2 << endl;

    return 0;
}
