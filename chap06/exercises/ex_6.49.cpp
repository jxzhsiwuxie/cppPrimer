//练习 6.49：什么是候选函数？什么是可行函数？


/*
* 候选函数：在函数调用时，满足如下条件的函数集中的函数称为候选函数：
* （1）函数名与被调用函数名相同。
* （2）函数的声明在调用点可见。
*/

/*
* 可行函数：可行函数是候选函数的子集中的函数，这些函数还需要满足：
* （1）这些函数的形参的数量与调用时提供的实参的数量相等。
* （2）调用时提供的每个实参的类型要么与对应位置的形参类型相同，要么能转换成形参的类型。
*/
