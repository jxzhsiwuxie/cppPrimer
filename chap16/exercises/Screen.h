#ifndef JXZ_SCREEN_H_
#define JXZ_SCREEN_H_

#include <cstddef>
#include <iostream>
#include <string>

template <std::size_t W, std::size_t H>
class Screen {
    friend std::ostream &operator<<(std::ostream &os, const Screen<W, H> &item);
    friend std::istream &operator>>(std::istream &os, Screen<W, H> &item);

   public:
    typedef std::string::size_type pos;
    Screen() = default;
    Screen(char c) : height(H), width(W), contents(H * W, c) {}

    char get() const { return contents[cursor]; }  //读取光标处的字符，类内定义，隐式的内联。
    char get(pos r, pos c) const;                  //读取特定位置（r行c列）的字符。
    Screen &move(pos r, pos c);                    //移动到r行c列处。
    Screen &set(char ch);                          //设定光标位置处字符为 ch。
    Screen &set(pos r, pos c, char ch);            //设置 r 行 c 列处字符为 ch。

    void some_member() const;

    //根据对象是否是 const 重载 display 函数。
    Screen &display(std::ostream &os) {
        do_display(os);
        return *this;
    }

    const Screen &display(std::ostream &os) const {
        do_display(os);
        return *this;
    }

    pos size() const;

   private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;

    mutable std::size_t access_ctr;

    void do_display(std::ostream &os) const { os << contents; }
};

template <std::size_t W, std::size_t H>
inline char Screen<W, H>::get(pos r, pos c) const {
    pos row = r * width;
    return contents[row + c];
}

template <std::size_t W, std::size_t H>
inline Screen<W, H> &Screen<W, H>::move(pos r, pos c) {
    pos row = r * width;
    cursor = row + c;
    return *this;
}

template <std::size_t W, std::size_t H>
inline Screen<W, H> &Screen<W, H>::set(char ch) {
    contents[cursor] = ch;
    return *this;
}

template <std::size_t W, std::size_t H>
inline Screen<W, H> &Screen<W, H>::set(pos r, pos c, char ch) {
    contents[r * width + c] = ch;
    return *this;
}

template <std::size_t W, std::size_t H>
inline Screen<W, H>::pos Screen<W, H>::size() const {
    return height * width;
}
template <std::size_t W, std::size_t H>
std::ostream &operator<<(std::ostream &os, const Screen<W, H> &item) {
    std::size_t r;
    for (r = 0; r < item.height; ++r) {
        os << item.contents.substr(r * W, w) << std::endl;
    }
    return os;
}

template <std::size_t W, std::size_t H>
std::istream &operator>>(std::istream &is, Screen<W, H> &item) {
    char ch;
    is >> ch;
    item.contents = std::string(W * H, ch);
    return is;
}

#endif