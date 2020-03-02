//练习 7.24：给你的 Screen 类添加三个构造函数：一个默认构造函数；另一个构造函数接收宽和高的值，
//然后将 contents 初始化成给定数量的空白符；第三个构造函数接收宽和高的值以及一个字符，该字符作为初始化之后屏幕的内容。

#include <cstddef>
#include <string>

class Screen {
   public:
    typedef std::string::size_type pos;

    Screen() = default;
    Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht * width, ' ') {}
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
