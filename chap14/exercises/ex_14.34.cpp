//练习 14.34：定义一个函数对象类，令其执行 if-then-else 的操作：该类的调用运算符接受三个形参，
//它首先检查第一个形参。如果成功返回第二个形参的值；如果不成功则返回第三个形参的值。

#include <iostream>
#include <string>

template <typename T>
class IfThenElse {
   private:
   public:
    IfThenElse() = default;
    ~IfThenElse() = default;

    T &operator()(bool b, T &&v1, T &&v2) {
        if (b)
            return v1;
        else
            return v2;
    }
};

using std::cout;
using std::endl;
using std::string;

int main() {
    IfThenElse<string> strIfThenElse;

    cout << strIfThenElse(false, string("aaaaaaaa"), string("bbbbbbbbbbb")) << endl;
    cout << strIfThenElse(true, string("aaaaaaaa"), string("bbbbbbbbbbb")) << endl;

    return 0;
}
