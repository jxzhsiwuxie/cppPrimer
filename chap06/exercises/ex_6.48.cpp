//练习 6.48：说明下面这个循环的含义，它对 assert 的使用合理么？
// string s;
// while (cin >> s && s != sought) { } //空函数体
// assert(cin);

/*
* 循环获取字符串直到遇到换行、文件结尾或者获得的字符串与 sought 相等为止。
* 这里的 assert 不合理。
* assert 是为了检测原本不应该出现的错误而使用的，但是这里在循环正常退出的情况下也可能触发 assert，而原本这种情况完全是完全合理的。
*/
