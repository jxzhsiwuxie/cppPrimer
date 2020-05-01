//练习 13.14：假定 numbered 是一个类，它有一个默认构造函数，能为每一个对象生成一个唯一的序列号，保存在名为 mysn 的数据成员中。
//假定 numbered 使用合成的拷贝控制成员，并给定如下的函数：
//     void f(numbered s){cout << s.mysn << endl; }
//则下面代码输出什么内容？
//     numbered a, b = a, c = b;
//     f(a); f(b); f(c);


/*
* 输出的内容相同，都等于  a.mysn。
*/
