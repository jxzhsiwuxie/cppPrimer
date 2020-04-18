//练习 12.5：我们未编写一个接受 initializer_list explicit（参见 7.5.4 节，第 264 页）参数的构造函数。讨论这个设计策略的优点和缺点。

/*
* 当使用 explicit 关键字声明构造函数时，它将只能以直接初始化的形式使用。而且，编译器将不会在自动转换过程中使用该构造函数。
* 所以，这里没使用 explici 来声明构造函数使得我们可以方便的使用 StrBlob b1 = {"aa", "bb", "cc"}; 这样的变量声明。
* 缺点就是当同时存在与 StrBlob 类型和其它容器类型比如 vector<string> 的成员函数时，调用时就有可能发生误解，比如下面这样
*   int compare(const std::vector<std::string> &svec) {return svec.size();}
*   int compare(const StrBlob &sb) {return sb.size();}
* 这样的调用 std::cout << b1.compare({"ded", "ccc"}) << std::endl; 就会发生误解，如果使用了 excplicit 则会提醒强制使用显式的形式。
*/
