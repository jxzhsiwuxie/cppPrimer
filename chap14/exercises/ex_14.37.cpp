//练习 14.37：编写一个类，令其检查两个值是否相等。使用该对象及标准库算法编写程序，
//令其替换某个序列中具有给定值的所有实例。

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

template <typename T>
class IfEqual {
   private:
    T target;
    T replace;

   public:
    IfEqual(const T &tag, const T &rep) : target(tag), replace(rep) {}
    ~IfEqual() = default;

    bool operator()(T &item) {
        try {
            if (item == target) {
                item = replace;
                return true;
            }
            return false;
        } catch (const std::exception &e) {
            std::cerr << e.what() << '\n';
            return false;
        }
    }
};

int main() {
    vector<string> svec = {"aaa", "bbb", "ccc", "ddd", "aa", "ccc", "aaa", "bbb"};

    std::for_each(svec.cbegin(), svec.cend(), [](const string &s) {
        cout << s << " ";
    });
    cout << endl;
    cout << "---------------------------" << endl;

    IfEqual<string> replace("aaa", "eee");
    std::for_each(svec.begin(), svec.end(), replace);

    std::for_each(svec.cbegin(), svec.cend(), [](const string &s) {
        cout << s << " ";
    });
    cout << endl;

    return 0;
}
