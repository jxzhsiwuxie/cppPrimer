//练习 15.38：下面的声明合法么？如果不合法，请解释原因；如果合法，请指出该声明的含义。
// BinaryQuery a = Query("fiery") & Query("bird");
// AndQuery b = Query("fiery") & Query("bird");
// OrQuery b = Query("fiery") & Query("bird");

/*
* 不合法，Query 类与 BinaryQuery 类不存在继承关系，不存在隐式的类型转换。
* 不合法，Query 类与 AndQuery 类不存在继承关系，不存在隐式的类型转换。
* 不合法，Query 类与 OrQuery 类不存在继承关系，不存在隐式的类型转换。
*/