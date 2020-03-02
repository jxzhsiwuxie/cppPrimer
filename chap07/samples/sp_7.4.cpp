//定义 Window_mgr 类，，并将它设置为 Screen 类的友元。

// #include <vector>
// #include <string>

// class Screen;

// class Window_mgr {
//    public:
//     using ScreenIndex = std::vector<Screen>::size_type;
//     void clear(ScreenIndex);
//    private:
//     std::vector<Screen> screens{Screen(24, 80, ' ')};
// };

// void Window_mgr::clear(ScreenIndex i){
//     Screen s = screens[i];
//     s.contents = std::string(s.height * s.width, ' ');
// }