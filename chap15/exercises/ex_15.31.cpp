//练习 15.31：已知 s1、s2、s3 和 s4 都是 string，判断下面的表达式分别创建了什么样的对象：
// (a) Query(s1) | Query(s2) & ~ Query(s3);
// (b) Query(s1) | (Query(s2) & ~ Query(s3));
// (c) (Query(s1) & (Query(s2)) | (Query(s3) & Query(s4))) ;

/*
* (a) 返回一个 AndQuery 对象，AndQuery 绑定到一个 OrQuery 对象和一个 NotQuery 对象上，OrQuery 对象绑定到两个 WordQuery 对象，分别存放着 s1 和 s2，
*     NotQuery 对象中存放着 s3。
*/

/*
* (b) 返回一个 OrQuery 对象，OrQuery 对象绑定到一个存放着 s1 的 WordQuery 和一个 AndQuery 对象上，
*     AndQuery 绑定到一个存放着 s2 的 WordQuery 和一个存放着 s3 的 NotQuery 对象上。
*/

/*
* (c) 返回一个 OrQuery 对象，绑定到两个 AndQuery 对象上，第一个 AndQuery 绑定到两个分别存放着 s1 和 s2 的 WordQuery 上，
*     第二个 AndQuery 绑定到两个分别存放着 s3 和 s4 的 WordQuery 上。
*/
