//练习 16.18：解释下面美俄个函数模板声明并指出它们是否非法。更正你发现的每个错误。
// (a) template<typename T, U, typename V> void f1(T, U， V);
// (b) template<typename T> T f2(int &T);
// (c) inline template<typename T> T foo(T, unsigned int*);
// (d) template <typename T> f4(T, T);
// (e) typedef char Ctype;
//     template <typename Ctype> Ctype f5(Ctype a);


/*
* (a) 非法，每个泛型参数前面都要加上关键字 typename 或者 class，应改为：
*     template<typename T, typename U, typename V> void f1(T, U， V);
*/

/*
* (b) 非法，泛型参数不是一个变量，应改为：
*     template<typename T> T f2(T &);
*/

/*
* (c) 非法，模板函数不能声明为 inline 的，应改为：
*     template<typename T> T foo(T, unsigned int*);
*/

/*
* (d) 非法，没有返回值，可以改为：
*     template <typename T> T f4(T, T);
*/

/*
* (e) 非法，Ctype 只是一个类型别名，不能作为泛型形参，可改为：
*     typedef char Ctype;
*     Ctype f5(Ctype a);
*/

