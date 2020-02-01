//练习 3.12：下列 vector 对象的定义由不正确的么？如果有，请指出来。对于正确的，
//描述其执行结果；对于不正确的，说明其错误的原因。

/*
* (a) vector<vector<int>> ivec;
* (b) vector<string> svec = ivec;
* (c) vector<string> svec(10, "null");
*/

/*
* (a) 定义正确。ivec 是一个 vector 对象，其元素类型是 vector<int>。
* (b) 定义不正确。svec 元素的类型是 string，ivec 元素的类型是 vector<int>，两者不一样，所以不能利用 ivec 初始化 svec。
* (c) 定义正确。svec 是一个包含 10 个元素并且每个元素都是字符串 "null" 的 vector 对象。
*/

