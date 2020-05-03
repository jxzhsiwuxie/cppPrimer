//自定义类似于 vector 的结构

#include <cstddef>
#include <memory>
#include <string>
#include <utility>

class StrVec {
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
    //默认构造函数，将指针都初始化为空，alloc 成员被隐式初始化
    StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
    StrVec(const StrVec &);             //拷贝构造函数
    StrVec &operator=(const StrVec &);  //拷贝赋值运算符
    ~StrVec();                          //析构函数

    void push_back(const std::string &);  //拷贝元素
    std::size_t size() const { return first_free - elements; }
    std::size_t capacity() const { return cap - elements; }
    std::string *begin() const { return elements; }
    std::string *end() const { return first_free; }
};

StrVec::StrVec(const StrVec &s) {
    //调用 alloc_n_copy 分配空间以容纳与 s 中一样多的元素
    auto new_data = alloc_n_copy(s.begin(), s.end());
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

void StrVec::push_back(const std::string &s) {
    chk_n_alloc();  //确保有空间容纳新元素
    //在 first_free 指向的元素中构造 s 的副本
    alloc.construct(first_free++, s);
}

std::pair<std::string *, std::string *> StrVec::alloc_n_copy(const std::string *beg, const std::string *end) {
    //分配空间，保存指定范围中的元素
    auto data = alloc.allocate(end - beg);
    //初始化并返回一个 pair，该 pair 由 data 和 uninitialized_copy 的返回值构成
    return {data, std::uninitialized_copy(beg, end, data)};
}

void StrVec::free() {
    //不能传递给 deallocate 一个空指针，如果 elementd 为 0，函数什么也不做
    if (elements) {
        //逆序销毁旧的元素
        for (auto p = first_free; p != elements; --p)
            alloc.destroy(--p);

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
