//练习 15.18：假设给定了第 543 页和第 544 页的类，同时已知每个对象的类型如注释所示，判断下面哪些赋值语句是合法的。
//解释哪些不合法的语句为什么不被允许。
// Base *p = &d1;   // d1 的类型是 Pub_Derv
// p = &d2;         // d2 的类型是 Priv_Derv
// p = &d3;         // d3 的类型是 Prot_Derv
// p = &dd1;        // dd1 的类型是 Derived_from_public
// p = &dd2;        // dd2 的类型是 Derived_from_Private
// p = &dd3;        // dd3 的类型是 Derived_from_Protected

/*
* 这里的赋值方式都是从派生类向基类的类型转换，只有当派生类是公有继承时，用户代码才能使用从派生类向基类转换。
* Base *p = &d1;        合法的
* p = &d2;              不合法的，d2 是 Base 的私有继承
* p = &d3;              不合法的，d3 是 Base 的保护继承
* p = &dd1;             合法的
* p = &dd2;             不合法的，dd2 是 Base 的间接的私有继承
* p = &dd3;             不合法的，dd3 是 Base 的间接的保护继承
*/

class Base {
   public:
    void pub_mem();

   protected:
    int prot_mem();

   private:
    char priv_mem();
};

struct Pub_Derv : public Base {
};

struct Prot_Derv : protected Base {
};

struct Priv_Derv : private Base {
};

struct Derived_from_public : public Pub_Derv {
};

struct Derived_from_protect : public Prot_Derv {
};

struct Derived_from_private : public Priv_Derv {
};

int main() {
    return 0;
}
