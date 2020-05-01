//练习 13.17：分别编写前三题中的 numbered 和 f，验证你是否正确预测了输出结果。

#include <ctime>
#include <iostream>

using std::cout;
using std::endl;

class numbered1 {
   private:
    static unsigned long long unique_id;

   public:
    numbered1() : mysn(unique_id++){};
    unsigned long long mysn;
};
unsigned long long numbered1::unique_id = 0;

void f1(numbered1 s) {
    cout << "mysn 的值为：" << s.mysn << endl;
}

void test1() {
    numbered1 a, b = a, c = b;
    f1(a);
    f1(b);
    f1(c);
}

//--------------------------------------
class numbered2 {
   private:
    static unsigned long long unique_id;

   public:
    numbered2() : mysn(unique_id++){};
    numbered2(const numbered2 &) : mysn(unique_id++){};
    unsigned long long mysn;
};
unsigned long long numbered2::unique_id = 0;

void f2(numbered2 s) {
    cout << "mysn 的值为：" << s.mysn << endl;
}

void test2() {
    numbered2 a, b = a, c = b;
    f2(a);
    f2(b);
    f2(c);
}

//-----------------------------------------

class numbered3 {
   private:
    static unsigned long long unique_id;

   public:
    numbered3() : mysn(unique_id++){};
    unsigned long long mysn;
};
unsigned long long numbered3::unique_id = 0;

void f3(const numbered3 &s) {
    cout << "mysn 的值为：" << s.mysn << endl;
}

void test3() {
    numbered3 a, b = a, c = b;
    f3(a);
    f3(b);
    f3(c);
}

int main() {
    cout << "-------------------------------" << endl;
    test1();
    cout << "-------------------------------" << endl;
    test2();
    cout << "-------------------------------" << endl;
    test3();
    cout << "-------------------------------" << endl;
    return 0;
}
