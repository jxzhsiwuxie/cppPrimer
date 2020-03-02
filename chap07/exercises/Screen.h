#ifndef SCREEN_H_
#define SCREEN_H_

#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

//前向声明。
class Screen;

class Window_mgr {
   public:
    Window_mgr();
    using ScreenIndex = std::vector<Screen>::size_type;
    void clear(ScreenIndex);

   private:
    std::vector<Screen> screens;
};

//定义 Screen 类并声明友元函数。
class Screen {
    friend void Window_mgr::clear(Window_mgr::ScreenIndex);

   public:
    typedef std::string::size_type pos;
    Screen() = default;
    Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * width, c) {}

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

   private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;

    mutable std::size_t access_ctr;

    void do_display(std::ostream &os) const { os << contents; }
};

//Window_mgr 默认构造函数。
Window_mgr::Window_mgr() {
    screens.push_back(Screen(20, 40, ' '));
}

// clear 函数。
void Window_mgr::clear(ScreenIndex i) {
    Screen s = screens[i];
    s.contents = std::string(s.height * s.width, ' ');
}

//定义 Screen 的内联函数。
inline char Screen::get(pos r, pos c) const {
    pos row = r * width;
    return contents[row + c];
}

inline Screen &Screen::move(pos r, pos c) {
    pos row = r * width;
    cursor = row + c;
    return *this;
}

inline Screen &Screen::set(char ch) {
    contents[cursor] = ch;
    return *this;
}

inline Screen &Screen::set(pos r, pos c, char ch) {
    contents[r * width + c] = ch;
    return *this;
}

#endif
