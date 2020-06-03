//练习 16.45：给定下面的模板，如果我们对一个像 42 这样的字面常量调用 g，解释会发生什么？
//如果我们对一个 int 类型的变量调用 g 呢？
// template<typename T> void g(T&& val){vector<T> v;}

/*
* 1）v 是一个 vector<int> 类型变量
* 2）v 是一个 vector<int &> 类型变量
*/
