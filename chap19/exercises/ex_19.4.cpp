//练习 19.4：使用上一个练习定义的类改写下面的代码，将表达式 *pa 转换成 C&：
// if (C *pc = dynamic_cast<C *>(pa)){
//     //使用 C 的成员
// } else {
//     // 使用 A 的成员
// }

class A { /* ... */
   public:
    virtual ~A() = default;
};

class B : public A { /* ... */
   public:
    virtual ~B() = default;
};

class C : public B { /* ... */
   public:
    virtual ~C() = default;
};

class D : public B, public A { /* ... */
   public:
    virtual ~D() = default;
};

int main() {
    A *pa = new C;
    if (C *pc = dynamic_cast<C *>(pa)) {
        //使用 C 的成员
    } else {
        // 使用 A 的成员
    }

    return 0;
}