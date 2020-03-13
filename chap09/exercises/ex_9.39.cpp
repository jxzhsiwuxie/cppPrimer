//练习 9.39：解释下面程序片段做了什么。
// vector<string> svec;
// svec.reserve(1024);
// string word;
// while (cin >> word)
//     svec.push_back(word);
// svec.resize(svec.size() + svec.size() / 2);

/*
* 创建 stirng 类型的 vector，初始化为空的。
* 为 svec 申请可以存放 1024 个 string 对象的空间。
* 从输入流中循环读取字符串并将其存入 svec 中。
* 请求将 svec 的空间扩展为可以存放现有元素数目 1.5 倍的空间。
* 如果 svec 中当前 string 对象数目的 1.5 倍小于 1024 则什么都不会改变，否则 svec 的 capacity 变为当前元素数目的 1.5 倍大小。
*/
