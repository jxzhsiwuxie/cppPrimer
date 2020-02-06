//练习 4.32：解释下面这个循环的含义。
// constexpr int size = 5;
// int ia[size] = {1, 2, 3, 4, 5};
// for (int *ptr = ia, ix = 0; ix != size && ptr != ia + size; ++ix, ++ptr) { /*...*/}

/*
* 定义并初始化指向数组 ia 首元素的指针 ptr，初始值为 0 的 int 类型变量 ix，
* 每次循环判断 ix 是否不等于 size 同时 ptr 不是指向数组尾元素的下一位置，
* 如果判断通过则执行循环体内容然后将 ix 加 1 同时将 ptr 指向下一个元素。
*/
