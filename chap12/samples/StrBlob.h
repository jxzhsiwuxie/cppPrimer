#ifndef STR_BLOB_H_
#define STR_BLOB_H_

#include <initializer_list>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

class StrBlobPtr;
class StrBlob {
    friend class StrBlobPtr;

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
    void pop_back();
    //元素访问
    std::string &front();
    std::string &back();

    ~StrBlob();

    //返回指向首元素和尾后元素的 StrBlobPtr
    StrBlobPtr begin() { return StrBlobPtr(*this); }
    StrBlobPtr end() {
        auto ret = StrBlobPtr(*this, data->size());
        return ret;
    }
};

StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()) {
}

StrBlob::StrBlob(std::initializer_list<std::string> il) : data(std::make_shared<std::vector<std::string>>(il)) {
}

StrBlob::~StrBlob() {}

void StrBlob::check(size_type i, const std::string &msg) const {
    if (i >= data->size())
        throw std::out_of_range(msg);
}

std::string &StrBlob::front() {
    check(0, "front on empty StrBlob");
    return data->front();
}

std::string &StrBlob::back() {
    check(0, "back on empty StrBlob");
    return data->back();
}

void StrBlob::pop_back() {
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

#endif