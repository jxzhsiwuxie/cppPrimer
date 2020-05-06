//练习 14.3：string 和 vector 都定义了重载的 == 以比较各自的对象，假设 svec1 和 svec2 是存放 string 的 vector，
//确定在下面的表达式中使用了哪个版本的 ==？
// (a) "cobble" == "stone"          (b) svec1[0] == svec2[0]
// svec1 == svec2                   (d) svec1[0] == "stone"

/*
* (a) 使用内置的，const char* 的 ==
* (b) 使用 string 的 ==
* (c) 使用 vector 的 ==
* (d) 使用 string 的 ==
*/
