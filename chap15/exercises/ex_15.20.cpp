//练习 15.20：编写代码检查你对前两题的回答是否正确。


class Base {
   public:
    void pub_mem();

   protected:
    int prot_mem();

   private:
    char priv_mem();
};

struct Pub_Derv : public Base {
    void memfcn (Base &b) { b = *this; }
};

struct Prot_Derv : protected Base {
    void memfcn (Base &b) { b = *this; }
};

struct Priv_Derv : private Base {
    void memfcn (Base &b) { b = *this; }
};

struct Derived_from_public : public Pub_Derv {
    void memfcn (Base &b) { b = *this; }
};

struct Derived_from_protect : public Prot_Derv {
    void memfcn (Base &b) { b = *this; }
};

struct Derived_from_private : public Priv_Derv {
    void memfcn (Base &b) { b = *this; }
};

int main() {
    Pub_Derv d1;
    Priv_Derv d2;
    Prot_Derv d3;
    Derived_from_public dd1;
    Derived_from_private dd2;
    Derived_from_protect dd3;

    Base *p = &d1;  // d1 的类型是 Pub_Derv
    p = &d2;        // d2 的类型是 Priv_Derv
    p = &d3;        // d3 的类型是 Prot_Derv
    p = &dd1;       // dd1 的类型是 Derived_from_public
    p = &dd2;       // dd2 的类型是 Derived_from_Private
    p = &dd3;       // dd3 的类型是 Derived_from_Protected

    return 0;
}
