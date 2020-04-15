//练习 11.29：如果给定的关键字不在容器中，upper_bound、lower_bound 和 equal_range 分别会返回什么？

/*
* 如果给定的关键字不在容器（假设为 con）中：
* upper_bounder 和 lower_bound 都会返回 con.end()；
* equal_range  将返回 pair<con.end(), con.end()>。
*/
