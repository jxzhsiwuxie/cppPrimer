//练习 4.33：根据 4.12 节中的表说明下面这条表达式的含义。
// somevalue ? ++x, ++y : --x, --y

/*
* 由 4.12 节的表可知表达式中使用到的运算符的优先级由高到低依次是：++/--、? : 、,
* 所以表达式表示：
* 如果 somevalue 判断为真，则将 x 和 y 分别加一，否则将 x 和 y 分别减一。
*/
