//练习 14.1：什么情况下重载的运算符与内置运算符有所区别？在什么情况下重载运算符由于内置运算符一样？

/*
* 当运算符本身运用在内置类型上指定了求值顺序或者具有特殊性质（短路性质）的时候，重载运算符与内置运算符有所区别，重载的版本无法保留这些性质。
* 除此之外的运算符，重载的版本和内置的版本是一样的。
*/
