//练习 9.10：下面 4 个对象分别是什么类型？
// vector<int> v1;
// const vector<int> v2;
// auto it1 = v1.begin(),       it2 = v2.begin();
// auto it3 = v1.cbegin(),      it4 = v2.cbegin();

/*
* it1 是 vector<int>::iterator 类型，it2 是 vector<int>::const_iterator；由于一条语句中只能声明一种类型，所以这一条语句语法错误。
* it3 和 it4 都是 vector<int>::const_iterator 类型。
*/

