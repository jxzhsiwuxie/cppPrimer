//练习4.24：本节示例程序将成绩划分为 high pass、pass he fail 三种，它的依据是条件运算符满足右结合律。
//假如条件运算符满足的是左结合律，求值过程是怎样的？

/*
* 示例程序：
* string finalgrade = (grade > 90) ? "high pass" : (grade < 60) ? "fail" : "pass";
* 加入条件运算满足的是左结合律，则当 grade 小于等于 90 的时候表达式返回的就不再是 fail 或者 pass
* 而是 grade < 60 的结果，一个布尔值，与 finalgrade 的类型不匹配，表达式就会出错。
*/
