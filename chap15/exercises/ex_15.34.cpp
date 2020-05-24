//练习 15.34：针对图 15.3（第 565 也）构建的表达式：
// (a) 列举出在处理表达式的构成中执行的所有构造函数。
// (b) 列举出 cout << q; 所调用的 repo。
// (c) 列举出 q.eval(); 所调用的 eval。

/*
* (a) Query、WordQuery、AndQuery、OrQuery、BinaryQuery 和 Query_base
* (b) cout << q; 调用 BinaryQuery::repo
* (c) q.eval(); 调用 OrQuery::eval，然后又调用 AndQuery::eval
*/
