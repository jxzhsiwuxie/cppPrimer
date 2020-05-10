#ifndef JXZH_STR_VEC_H_
#define JXZH_STR_VEC_H_

#include <algorithm>
#include <cstddef>
#include <cstring>
#include <initializer_list>
#include <iostream>
#include <memory>
#include <string>
#include <utility>

class StrVec {
    friend bool operator==(const StrVec &, const StrVec &);
    friend bool operator!=(const StrVec &, const StrVec &);
    friend bool operator<(const StrVec &, const StrVec &);

   private:
    static std::allocator<std::string> alloc;  //用来分配元素，被添加元素的函数所使用
    void chk_n_alloc() {
        if (size() == capacity())
            reallocate();
    }
    //工具函数，被拷贝构造函数、赋值运算符和析构函数使用
    std::pair<std::string *, std::string *> alloc_n_copy(const std::string *, const std::string *);
    void free();              //销毁元素并释放内存
    void reallocate();        //获得更多内存并拷贝现有元素
    std::string *elements;    //指向数组首元素的指针
    std::string *first_free;  //指向数组第一个空闲元素的指针
    std::string *cap;         //指向数组尾后元素的指针

   public:
    //默认构造函数，将指针都初始化为空，alloc 成员被隐式初始化（？？？）
    StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
    StrVec(const StrVec &);  //拷贝构造函数
    StrVec(const std::initializer_list<std::string> &);
    StrVec(StrVec &&) noexcept;             //移动构造函数
    StrVec &operator=(const StrVec &);      //拷贝赋值运算符
    StrVec &operator=(StrVec &&) noexcept;  //移动赋值运算符
    StrVec &operator=(std::initializer_list<std::string> &);
    std::string &operator[](std::size_t);
    std::string &operator[](std::size_t) const;
    ~StrVec();  //析构函数

    void push_back(const std::string &);  //拷贝元素
    void push_back(std::string &&);       //移动元素
    std::size_t size() const { return first_free - elements; }
    std::size_t capacity() const { return cap - elements; }
    std::string *begin() const { return elements; }
    std::string *end() const { return first_free; }

    //调整数组的大小为 n，若 n < size()，则丢弃多余的元素，若要添加元素，则对新元素进行值初始化
    void resize(std::size_t n);
    void resize(std::size_t n, const std::string &s);
    //分配至少能容纳 n 个元素的内存空间
    void reserve(std::size_t n);
};

//静态成员需要在类外定义，否则无法使用
std::allocator<std::string> StrVec::alloc;

StrVec::StrVec(const StrVec &s) {
    //调用 alloc_n_copy 分配空间以容纳与 s 中一样多的元素
    auto new_data = alloc_n_copy(s.begin(), s.end());
    elements = new_data.first;
    first_free = cap = new_data.second;
}

StrVec::StrVec(StrVec &&s) noexcept  //移动操作不应抛出任何异常
    //成员初始化器接管 s 中的资源
    : elements(s.elements), first_free(s.first_free), cap(s.cap) {
    //令 s 进入这样的状态————对其运行析构函数是安全的
    s.elements = s.first_free = s.cap = nullptr;
}

StrVec::StrVec(const std::initializer_list<std::string> &il) {
    auto new_data = alloc_n_copy(il.begin(), il.end());
    elements = new_data.first;
    first_free = cap = new_data.second;
}

StrVec::~StrVec() {
    free();
}

StrVec &StrVec::operator=(const StrVec &rhs) {
    //调用 alloc_n_copy 分配内存，大小与 rhs 中元素占用空间一样多
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

StrVec &StrVec::operator=(StrVec &&rhs) noexcept {
    //直接检测自赋值
    if (this != &rhs) {
        free();                   //释放已有内存
        elements = rhs.elements;  //从 rhs 接管资源
        first_free = rhs.first_free;
        cap = rhs.cap;
        //将 rhs 置于可析构状态
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }

    return *this;
}

StrVec &StrVec::operator=(std::initializer_list<std::string> &il) {
    auto data = alloc_n_copy(il.begin(), il.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

void StrVec::push_back(const std::string &s) {
    chk_n_alloc();  //确保有空间容纳新元素
    //在 first_free 指向的元素中构造 s 的副本
    alloc.construct(first_free++, s);
}

void StrVec::push_back(std::string &&s) {
    chk_n_alloc();
    alloc.construct(first_free++, std::move(s));
}

std::pair<std::string *, std::string *> StrVec::alloc_n_copy(const std::string *beg, const std::string *end) {
    //分配空间，保存指定范围中的元素
    auto data = alloc.allocate(end - beg);
    //初始化并返回一个 pair，该 pair 由 data 和 uninitialized_copy 的返回值构成
    return {data, std::uninitialized_copy(beg, end, data)};
}

void StrVec::free() {
    //不能传递给 deallocate 一个空指针，如果 elements 为 0，函数什么也不做
    if (elements) {
        //逆序销毁旧的元素
        for (auto p = first_free; p != elements;)
            alloc.destroy(--p);

        // std::for_each(elements, first_free, [](std::string s) {
        //     alloc.destroy(&s);
        // });

        alloc.deallocate(elements, cap - elements);
    }
}

void StrVec::reallocate() {
    //我们分配当前大小两倍的内存空间
    auto new_capacity = size() ? 2 * size() : 1;
    //分配新内存
    auto new_data = alloc.allocate(new_capacity);
    //将数据从旧内存移动到 新内存
    auto dest = new_data;  //指向新数组中下一个空闲的位置
    auto elem = elements;  //指向旧数组中下一个元素
    for (std::size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, std::move(*elem++));
    free();  //一旦我们移动完元素，就释放旧的内存空间
    //更新我们的数据结构，执行新的元素
    elements = new_data;
    first_free = dest;
    cap = elements + new_capacity;
}

void StrVec::reserve(std::size_t n) {
    if (n <= capacity())
        return;

    auto new_data = alloc.allocate(n);
    //将数据从旧内存移动到 新内存
    auto dest = new_data;  //指向新数组中下一个空闲的位置
    auto elem = elements;  //指向旧数组中下一个元素
    for (std::size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, std::move(*elem++));
    free();  //一旦我们移动完元素，就释放旧的内存空间
    //更新我们的数据结构，执行新的元素
    elements = new_data;
    first_free = dest;
    cap = elements + n;
}

void StrVec::resize(std::size_t n, const std::string &s) {
    auto new_first_free = elements + n;
    if (n <= size()) {
        while (first_free != new_first_free)
            alloc.destroy(--first_free);
    } else if (n > size() && n <= capacity()) {
        while (first_free != new_first_free)
            alloc.construct(first_free++, s);
    } else {
        auto new_data = alloc.allocate(n);
        //将数据从旧内存移动到 新内存
        auto dest = new_data;  //指向新数组中下一个空闲的位置
        auto elem = elements;  //指向旧数组中下一个元素
        for (std::size_t i = 0; i != size(); ++i)
            alloc.construct(dest++, std::move(*elem++));
        free();  //一旦我们移动完元素，就释放旧的内存空间
        //更新我们的数据结构，执行新的元素
        elements = new_data;
        first_free = dest;
        cap = elements + n;

        while (first_free != new_first_free)
            alloc.construct(first_free++, s);
    }
}

void StrVec::resize(std::size_t n) {
    std::string s;
    resize(n, s);
}

bool operator==(const StrVec &lhs, const StrVec &rhs) {
    bool res = lhs.size() == rhs.size() && lhs.capacity() == rhs.capacity();
    if (res) {
        std::size_t sz = lhs.size();
        for (std::size_t i = 0; i < sz; ++i) {
            if (*(lhs.elements + i) != *(rhs.elements + i)) {
                res = false;
                break;
            }
        }
    }

    return res;
}

bool operator!=(const StrVec &lhs, const StrVec &rhs) {
    return !(lhs == rhs);
}

bool operator<(const StrVec &lhs, const StrVec &rhs) {
    bool res = lhs.size() < rhs.size() && lhs.capacity() < rhs.capacity();
    if (res) {
        std::size_t sz = lhs.size();
        for (std::size_t i = 0; i < sz; ++i) {
            if (*(lhs.elements + i) > *(rhs.elements + i)) {
                res = false;
                break;
            }
        }
    }

    return res;
}

std::string &StrVec::operator[](std::size_t n) {
    return elements[n];
}

std::string &StrVec::operator[](std::size_t n) const {
    return elements[n];
}

#endif