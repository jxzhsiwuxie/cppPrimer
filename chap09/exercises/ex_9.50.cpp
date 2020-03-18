//练习 9.50：编写程序处理一个 vector<string>，其元素都表示整型值。
//计算 vector 中所有元素之和。修改程序，使其计算表示浮点值的 string 之和。

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

int sumOfInts(const vector<string> &);

double sumOfDoubles(const vector<string> &);

int main() {
    //--------------------- 1    2    3.4    0.6    10     100     0.5
    vector<string> strs = {"1", "2", "3.4", "0.6", "0xa", "1e+2", "5e-1"};

    cout << "vector<string> 中包含的元素为：" << endl;
    for (const auto s : strs)
        cout << s << " ";
    cout << endl;

    int isum = sumOfInts(strs);
    cout << "所有元素转换成 int 类型之后和为：" << isum << endl;

    double dsum = sumOfDoubles(strs);
    cout << "所有元素转换成 double 类型之后和为：" << dsum << endl;

    return 0;
}

int sumOfInts(const vector<string> &strs) {
    int sum = 0;
    for (const auto s : strs) {
        int i = std::stoi(s.substr(s.find_first_of("+-.0123456789")));
        sum += i;
        cout << i << "  ";
    }
    cout << endl;

    return sum;
}

double sumOfDoubles(const vector<string> &strs) {
    double sum = 0;
    for (const auto s : strs) {
        double d = std::stod(s.substr(s.find_first_of("+-.0123456789")));
        sum += d;
        cout << d << "  ";
    }
    cout << endl;

    return sum;
}