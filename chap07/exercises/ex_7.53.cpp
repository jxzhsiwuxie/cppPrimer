//练习 7.53：定义你自己的 Debug。

class Debug {
   private:
    bool hw;     //硬件错误而非 IO 错误
    bool io;     //IO 错误
    bool other;  //其它错误

   public:
    constexpr Debug(bool b = true) : hw(b), io(b), other(b) {}
    constexpr Debug(bool h, bool i, bool o) : hw(h), io(i), other(o) {}
    constexpr bool any() { return hw || io || other; }
    void set_hw(bool b) { hw = b; }
    void set_io(bool b) { io = b; }
    void set_other(bool b) { other = b; }
};
