#ifndef STR_BLOB_H_
#define STR_BLOB_H_

#include <cstddef>
#include <initializer_list>
#include <memory>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

class StrBlobPtr;
class ConstStrBlobPtr;

class StrBlob {
    friend class StrBlobPtr;
    friend class ConstStrBlobPtr;

    friend bool operator==(const StrBlob &, const StrBlob &);
    friend bool operator!=(const StrBlob &, const StrBlob &);
    friend bool operator<(const StrBlob &, const StrBlob &);

   public:
    typedef std::vector<std::string>::size_type size_type;

   private:
    std::shared_ptr<std::vector<std::string>> data;
    //如果 data[i] 不合法，抛出异常
    void check(size_type i, const std::string &msg) const;

   public:
    StrBlob();
    StrBlob(std::initializer_list<std::string> il);
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    //添加和删除元素
    void push_back(const std::string &t) { data->push_back(t); }
    void push_back(std::string &&t) { data->push_back(std::move(t)); }
    void pop_back();
    //元素访问
    std::string &front();
    std::string &back();
    //const 版本的元素访问
    const std::string &front() const;
    const std::string &back() const;

    std::string &operator[](std::size_t);
    std::string &operator[](std::size_t) const;

    ~StrBlob();

    //返回指向首元素和尾后元素的 StrBlobPtr
    StrBlobPtr begin();
    StrBlobPtr end();

    ConstStrBlobPtr cbegin();
    ConstStrBlobPtr cend();
};

bool operator==(const StrBlob &lhs, const StrBlob &rhs) {
    return *(lhs.data) == *(rhs.data);
}

bool operator!=(const StrBlob &lhs, const StrBlob &rhs) {
    return !(lhs == rhs);
}

bool operator<(const StrBlob &lhs, const StrBlob &rhs) {
    return *(lhs.data) < *(rhs.data);
}

std::string &StrBlob::operator[](std::size_t n) {
    return (*data)[n];
}

std::string &StrBlob::operator[](std::size_t n) const {
    return (*data)[n];
}

#endif