//练习 5.17：假设有两个包含整数的 vector 对象，编写一段程序，检验其中一个 vector 对象是否是另一个的前缀。
//为了实现这一目标，对于两个不等长的 vector 对象，只需要挑出长度较短的哪个，把它的所有元素和另一个 vector 对象
//比较即可。例如，如果两个 vector 对象的元素分别是 0、1、1、2 和 0、1、1、2、3、5、8，则程序的返回结果应该为真。

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main() {
    vector<int> ivec1, ivec2;
    int tmp, smidx = 0;

    cout << "输入一组整数：" << endl;
    while (cin >> tmp)
        ivec1.push_back(tmp);

    cin.clear();
    cout << "再输入一组整数：" << endl;
    while (cin >> tmp)
        ivec2.push_back(tmp);

    if (ivec1.size() == ivec2.size())
        smidx = 0;
    else if (ivec1.size() < ivec2.size()) {
        smidx = 1;
        for (decltype(ivec1.size()) i = 0; i < ivec1.size(); ++i) {
            if (ivec1.at(i) != ivec2.at(i))
                smidx = 0;
        }
    } else {
        smidx = 2;
        for (decltype(ivec2.size()) i = 0; i < ivec2.size(); ++i) {
            if (ivec2.at(i) != ivec1.at(i))
                smidx = 0;
        }
    }

    cout << "第一组整数为：" << endl;
    for (decltype(ivec1.size()) i = 0; i < ivec1.size(); ++i)
        cout << ivec1.at(i) << " ";
    cout << endl;

    cout << "第二组整数为：" << endl;
    for (decltype(ivec2.size()) i = 0; i < ivec2.size(); ++i)
        cout << ivec2.at(i) << " ";
    cout << endl;

    if (smidx == 1)
        cout << "所以第一个 vector 对象是第二个的前缀" << endl;
    else if (smidx == 2)
        cout << "所以第二个 vector 对象是第一个的前缀" << endl;
    else
        cout << "所以两个 vector 对象没有前缀关系" << endl;

    return 0;
}
