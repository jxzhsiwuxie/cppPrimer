
#ifndef JXZ_BLOB_H_
#define JXZ_BLOB_H_

#include <initializer_list>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

template <typename T>
class BlobPtr;

template <typename T>
class Blob;

template <typename T>
bool operator==(const Blob<T> &, const Blob<T> &);
template <typename T>
bool operator!=(const Blob<T> &, const Blob<T> &);
template <typename T>
bool operator<(const Blob<T> &, const Blob<T> &);

//.............................................

template <typename T>
class Blob {
    friend class BlobPtr<T>;
    friend bool operator==(const Blob<T> &, const Blob<T> &);
    friend bool operator!=(const Blob<T> &, const Blob<T> &);
    friend bool operator<(const Blob<T> &, const Blob<T> &);

   public:
    typedef T value_type;
    typedef typename std::vector<T>::size_type size_type;

   private:
    std::shared_ptr<std::vector<T>> data;
    //若 data[i] 无效则抛出 msg
    void check(size_type i, const std::string &msg) const;

   public:
    //构造函数
    Blob();
    Blob(std::initializer_list<T> il);
    template <typename IT>
    Blob(IT b, IT e) : data(std::shared_ptr<std::vector<T>>(b, e)) {}
    ~Blob();
    //Blob 中的元素数目
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    //添加和删除元素
    void push_back(const T &t) { data->push_back(t); }
    void push_back(T &&t) { data->push_back(std::move(t)); }
    void pop_back();
    //元素访问
    T &back();
    T &front();
    T &back() const;
    T &front() const;
    T &operator[](size_type i);
    T &operator[](size_type i) const;

    BlobPtr<T> begin();
    BlobPtr<T> end();
};

template <typename T>
Blob<T>::Blob() : data(std::make_shared<std::vector<T>>()) {}

template <typename T>
Blob<T>::Blob(std::initializer_list<T> il) : data(std::make_shared<std::vector<T>>(il)) {}

template <typename T>
void Blob<T>::check(size_type i, const std::string &msg) const {
    if (i >= data->size())
        throw std::out_of_range(msg);
}

template <typename T>
void Blob<T>::pop_back() {
    check(0, "pop_back on empty Blob.");
    data->pop_back();
}

template <typename T>
T &Blob<T>::back() {
    check(0, "back on empty Blob.");
    return data->back();
}

template <typename T>
T &Blob<T>::front() {
    check(0, "front on empty Blob.");
    return data->front();
}

template <typename T>
T &Blob<T>::back() const {
    check(0, "back on empty Blob.");
    return data->back();
}

template <typename T>
T &Blob<T>::front() const {
    check(0, "front on empty Blob.");
    return data->front();
}

template <typename T>
T &Blob<T>::operator[](size_type i) {
    check(i, "subscript out of range.");
    return (*data)[i];
}

template <typename T>
T &Blob<T>::operator[](size_type i) const {
    check(i, "subscript out of range.");
    return (*data)[i];
}

template <typename T>
bool operator==(const Blob<T> &lhs, const Blob<T> &rhs) {
    return *(lhs.data) == *(rhs.data);
}

template <typename T>
bool operator!=(const Blob<T> &lhs, const Blob<T> &rhs) {
    return *(lhs.data) != *(rhs.data);
}

template <typename T>
bool operator<(const Blob<T> &lhs, const Blob<T> &rhs) {
    return *(lhs.data) < *(rhs.data);
}

//......................................................
template <typename T>
bool operator==(const BlobPtr<T> &, const BlobPtr<T> &);

template <typename T>
bool operator!=(const BlobPtr<T> &, const BlobPtr<T> &);

template <typename T>
class BlobPtr {
    friend bool operator==(const BlobPtr<T> &, const BlobPtr<T> &);
    friend bool operator!=(const BlobPtr<T> &, const BlobPtr<T> &);

   public:
    typedef T value_type;

   private:
    //若检查成功，check 返回一个指向 vector 的 shared_ptr
    std::shared_ptr<std::vector<T>> check(std::size_t, const std::string &) const;
    //保存一个 weak_ptr 表示底层 vector 可能被销毁
    std::weak_ptr<std::vector<T>> wptr;
    //数组中的当前位置
    std::size_t curr;

   public:
    //构造函数
    BlobPtr() : curr(0) {}
    BlobPtr(Blob<T> &a, std::size_t sz = 0) : wptr(a.data), curr(sz) {}
    T &operator*() const {
        auto p = check(curr, "deference pase end.");
        return (*p)[curr];
    }
    T &operator->() const {
        auto p = check(curr, "deference pase end.");
        return (*p)[curr];
    }
    //递增和递减
    BlobPtr &operator++();
    BlobPtr &operator--();
    BlobPtr &operator++(int);
    BlobPtr &operator--(int);
};

//-----
template <typename T>
BlobPtr<T> Blob<T>::begin() {
    return BlobPtr<T>(*this);
}

template <typename T>
BlobPtr<T> Blob<T>::end() {
    return BlobPtr<T>(*this, this->size());
}
//----

template <typename T>
std::shared_ptr<std::vector<T>> BlobPtr<T>::check(std::size_t i, const std::string &msg) const {
    // vector 是否还存在
    auto ret = wptr.lock();
    if (!ret)
        throw std::runtime_error("unbound StrBlobPtr");
    if (i > ret->size() - 1)
        throw std::out_of_range(msg);
    return ret;  //否则返回指向 vector 的 shared_ptr
}

template <typename T>
BlobPtr<T> &BlobPtr<T>::operator++() {
    check(curr, "increase pass end of BlobPtr");
    ++curr;
    return *this;
}

template <typename T>
BlobPtr<T> &BlobPtr<T>::operator--() {
    --curr;
    check(curr, "decrement past begin of BlobPtr");
    return *this;
}

template <typename T>
BlobPtr<T> &BlobPtr<T>::operator++(int) {
    BlobPtr ret = *this;
    ++this;
    return ret;
}

template <typename T>
BlobPtr<T> &BlobPtr<T>::operator--(int) {
    BlobPtr ret = *this;
    --this;
    return ret;
}

template <typename T>
bool operator==(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
    return *(lhs.wptr.lock()) == *(rhs.wptr.lock()) && lhs.curr == rhs.curr;
}

template <typename T>
bool operator!=(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
    return !(lhs == rhs);
}

#endif