//练习 7.20：友元在什么时候有用？请分别列出使用友元的利弊。

/*
* 当一个函数不是类的成员函数但是又希望访问类的非 public 成员的时候是有用的。
* 使用友元的好处就是即使在函数不是类的成员函数也能访问到原本被隐藏的数据；
* 这也是友元函数的弊端，破坏了类的封装的本意。
*/