//练习 5.16：while 特别适用于那些条件保持不变、反复执行操作的情况，例如，当未到达文件末尾时不断读取下一个值。
//for 循环则更像是在按步骤迭代，它的索引值在某个范围内依次变化。根据每种循环的习惯用法，各自编写一段程序，
//然后分别使用另一种循环改写。如果只能使用一种循环，尼更倾向于哪种呢？为什么？

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
    int iArr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sum = 0, idx = 0;

    for (int i = 0; i < 10; ++i)
        sum += iArr[i];
    cout << "用 for 循环得到数组元素和为：" << sum << endl;

    sum = 0;
    while (idx < 10)
        sum += iArr[idx++];
    cout << "用 while 循环得到数组元素和为：" << sum << endl;


    cout << "输入一组数字：" << endl;
    int ival1 = 0, sum1 = 0;
    while (cin >> ival1)
        sum1 += ival1;
    cout << "用 while 循环得到输入数字和为：" << sum1 << endl;

    cin.clear();
    cout << "再输入一组数字：" << endl;
    int ival2 = 0, sum2 = 0;
    for (; cin >> ival2;)
        sum2 += ival2;
    cout << "用 for 循环得到输入数字和为：" << sum2 << endl;

    return 0;
}

/*
* 如果只能使用一种循环的话，更倾向于使用 for 循环。控制更加紧凑，迭代页更加明确。
*/
