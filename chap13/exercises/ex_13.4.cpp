//练习 13.4：假定 Point 是一个类类型，它有一个 public 的拷贝构造函数，指出下面程序片段中哪些地方使用了拷贝构造函数：
// Point global;
// Point foo_bar(Point arg)
// {
//    Point local = arg, *heap = new Point(global);     //这里两次初始化都用到了
//    *heap = local;                                    //这里不是初始化，不会用到
//    Point pa[4] = {local, *hwap};                     //pa 数组前两个成员的初始化使用了拷贝构造函数，后两个使用默认构造函数
//    return *heap;                                     //返回一个非引用类类型的对象使用到 拷贝构造函数。
// }
