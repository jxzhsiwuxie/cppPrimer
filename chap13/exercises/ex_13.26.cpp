//练习 13.26：对上一题中描述的 StrBlob 类，编写你自己的版本。

#include <initializer_list>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

class StrBlob {
   public:
    typedef std::vector<std::string>::size_type size_type;

   private:
    std::shared_ptr<std::vector<std::string>> data;

   public:
    StrBlob() : data(std::make_shared<std::vector<std::string>>()) {}
    StrBlob(std::initializer_list<std::string> il) : data(std::make_shared<std::vector<std::string>>(il)) {}
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }

    //拷贝构造函数
    StrBlob(const StrBlob &rhs) : data(new std::vector<std::string>(*(rhs.data))) {}
    //拷贝赋值运算符
    StrBlob &operator=(const StrBlob &rhs) {
        auto newPtr = new std::vector<std::string>(*rhs.data);
        data.reset(newPtr);
    }

    ~StrBlob() = default;
};
