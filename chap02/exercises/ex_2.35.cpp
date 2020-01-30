//练习 2.35：判断下列定义推断出的类型是什么，然后编写程序进行验证。
/*
* const int i = 42;
* auto j = i;
* const auto &k = i;
* auto *p = &i;
* const auto j2 = i, &k2 = i;
*/

/*
* j 是 int 型变量。
* k 是一个整型常量的引用，绑定到 i。
* p 是一个指向整型常量的指针。
* j2 是一个整型常量。
* k2 是一个整型常量的引用，绑定到 i。
*/

int main()
{
    //变量定义
    const int i = 42;
    auto j = i;
    const auto &k = i;
    auto *p = &i;
    const auto j2 = i, &k2 = i;

    //验证
    j = 100; //可以将 j 重新赋值。

    k = 100;      //编译器报错，k 不可修改。
    int valk = k; //用 k 初始化一个 int 变量没问题。

    *p = 100;      //编译器报错，*p 不可修改。
    int valp = *p; //用 *p 初始化一个 int 变量没问题。
    p = &valp;     //将 p 指向新的对象也没问题。

    j2 = 100;       //编译器报错，j2 不可修改。
    int valj2 = j2; //用 j2 初始化一个 int 变量没问题。

    k2 = 100;       //编译器报错，k2 不可修改。
    int valk2 = k2; //用 k2 初始化一个 int 变量没问题。

    return 0;
}