//练习 12.21：也可以这样编写 StrBlobPtr 的 deref 成员：
// std::string &deref() const { return (*check(curr, "dereference past end"))[curr]; }
//你认为哪个版本更好，为什么？

/*
* 前一个更好。更清晰明确。
*/
