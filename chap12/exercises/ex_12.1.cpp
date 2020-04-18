//练习 12.1：在此代码的结尾，b1 和 b2 各包含多少个元素？
// StrBlob b1;
// {
//     StrBlob b2 = {"a", "an", "the"};
//     b1 = b2;
//     b2.push_back("about");
// }

/*
* b1 和 b2 共享同一个 vector<string> 对象。当代码结束后，b2 被销毁，里面不再包含数据，
* 但是 b1 内部包含的 data 指向的 vector<string> 对象中包含 4 个元素。
*/

