//练习 18.9：定义本书描述的书店程序异常类，然后为 Sales_data 类重新编写一个复合赋值运算符并令其抛出一个异常。

#include <stdexcept>
#include <string>

class out_of_stock : public std::runtime_error {
   public:
    explicit out_of_stock(const std::string &s) : std::runtime_error(s) {}
};

class isbn_mismatch : public std::logic_error {
   public:
    const std::string left, right;
    explicit isbn_mismatch(const std::string &s) : std::logic_error(s) {}
    isbn_mismatch(const std::string &s, const std::string &lhs, const std::string &rhs) : std::logic_error(s), left(lhs), right(rhs) {}
};
