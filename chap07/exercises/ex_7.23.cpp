//练习 7.23：编写你自己的 Screen 类。

#include <cstddef>
#include <string>

class Screen {
   public:
    typedef std::string::size_type pos;
    Screen() = default;
    Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * width, c) {}
    inline char get() const { return contents[cursor]; }  //读取光标处的字符。
    inline char get(pos r, pos c) const;                  //读取特定位置（r行c列）的字符。
    inline Screen &move(pos r, pos c);                    //移动到r行c列处。

    void some_member() const;

   private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;

    mutable std::size_t access_ctr = 0;
};

char Screen::get(pos r, pos c) const {
    pos row = r * width;
    return contents[row + c];
}

Screen &Screen::move(pos r, pos c) {
    pos row = r * width;
    cursor = row + c;
    return *this;
}

void Screen::some_member() const {
    ++access_ctr;
}
