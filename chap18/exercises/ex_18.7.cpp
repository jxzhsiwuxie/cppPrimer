//练习 18.7：根据第 16 章的介绍定义你自己的 Blob 和 BlobPtr，注意将构造函数写成函数 try 语句块。

#include <initializer_list>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

template <typename T>
class Blob {
   public:
    typedef T value_type;
    typedef typename std::vector<T>::size_type size_type;

   private:
    std::shared_ptr<std::vector<T>> data;

   public:
    Blob(std::initializer_list<T> il) try : data(std::make_shared<std::vector<T>>(il)) {
    } catch (const std::exception &e) {
    }
    template <typename IT>
    Blob(IT b, IT e) try : data(std::shared_ptr<std::vector<T>>(b, e)) {
    } catch (const std::exception &e) {
    }

    //...
};

template <typename T>
class BlobPtr {
   private:
    std::weak_ptr<std::vector<T>> wptr;
    //数组中的当前位置
    std::size_t curr;

   public:
    BlobPtr(Blob<T> &a, std::size_t sz = 0) try : wptr(a.data), curr(sz) {
    } catch (const std::exception &e) {
    }

    //...
};