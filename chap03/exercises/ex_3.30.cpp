//练习 3.30：指出下面代码中的索引错误。

// constexpr size_t array_size = 10;
// int ia[array_size];
// for (size_t ix = 1; ix <= array_size; ++ix)
//     ia[ix] = ix;

/*
* ia 包含 10 个元素，索引值从 0 到 9，循环中 ix <= array_size，
* 当 ix 等于 array_size 的时候，ia[ix] 读取了超出最大索引的值，造成缓冲区溢出错误。
*/