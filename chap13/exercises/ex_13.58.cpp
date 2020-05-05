//练习 13.58：编写新版本的 Foo 类，其 sorted 函数中右打印语句，测试这个类，来验证你对前两题的猜测是否正确。

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using std::cout;
using std::endl;
using std::sort;
using std::vector;

class Foo {
   private:
    vector<int> data;

   public:
    Foo sorted() && {
        sort(data.begin(), data.end());

        cout << "调用 && 版本的 sorted " << endl;
        return *this;
    }
    Foo sorted() const& {
        // Foo ret(*this);
        // sort(ret.data.begin(), ret.data.end());
        // cout << "调用 const & 版本的 sorted " << endl;
        // return ret;

        // Foo ret(*this);
        // cout << "调用 const & 版本的 sorted " << endl;
        // return ret.sorted();

        Foo ret(*this);
        cout << "调用 const & 版本的 sorted " << endl;
        return Foo(*this).sorted();
    }

    void push_back(int n) { data.push_back(n); }
    void print() const {
        for (auto n : data)
            cout << n << " ";
        cout << endl;
    }
};

int main() {
    Foo foo;
    foo.push_back(235);
    foo.push_back(53);
    foo.push_back(23342);
    foo.push_back(523);
    foo.push_back(12);
    foo.push_back(314);
    foo.push_back(53);
    foo.push_back(1412);

    foo.print();
    cout << "----------------------" << endl;

    foo.sorted().print();
    cout << "----------------------" << endl;

    // std::move(foo).sorted().print();
    // cout << "----------------------" << endl;

    return 0;
}
