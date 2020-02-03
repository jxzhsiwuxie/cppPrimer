//练习 3.37：下面程序适合含义，程序的输出结果是什么？

// const char ca[] = {'h', 'e', 'l', 'l', 'o'};
// const char *cp = ca;
// while(*cp) {
//     cout << *cp << endl;
//     ++cp;
// }

/*
* 首先定义了一个常量字符数组 ca，
* 然后定义一个指向常量字符的指针 cp，
* 将数组名也就是字符数组首元素的地址赋给 cp，
* 然后通过指针 cp 遍历数组 ca 中的字符。
*/

/*
* 程序输出的结果是未知的。
* 字符数组中没有空字符 '\0'，所以通过 cp 遍历的时候，遍历到 ca 结尾处，while 循环的判定条件仍然为 true，
* 循环将继续遍历字符 'o' 地址之后的地址中内容直到遇到空字符为止。
*/