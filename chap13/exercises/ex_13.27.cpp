//练习 13.27：定义你自己的使用引用计数版本的 HasPtr。

#include <cstddef>
#include <string>

class HasPtr {
   private:
    std::string *ps;
    int i;
    std::size_t *use;  //用来记录有多少个对象共享 *ps 的成员
   public:
    //构造函数分配新的 string 和新的计数器，将计数器置为 1
    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0), use(new std::size_t(1)) {}
    //拷贝构造函数拷贝所有三个数据成员并递增计数器
    HasPtr(const HasPtr &p) : ps(p.ps), i(p.i), use(p.use) { ++*use; }
    //拷贝赋值运算符
    HasPtr &operator=(const HasPtr &rhs) {
        ++*rhs.use;         //递增右侧运算对象的引用计数
        if (--*use == 0) {  //递减左侧运算对象的引用计数
            delete ps;      //如果没有其它用户了，则释放左侧运算对象分配的成员
            delete use;
        }

        ps = rhs.ps;
        i = rhs.i;
        use = rhs.use;
        return *this;
    }
    //析构函数
    ~HasPtr() {
        if (--*use == 0) {
            delete ps;
            delete use;
        }
    }
};
