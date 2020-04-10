//练习 10.41：仅根据算法和参数的名字，描述下面每个标准可算法执行什么操作：
// replace(beg, end, old_val, new_val)
// replace_if(beg, end, preb, new_val)
// replace_copy(beg, end, dest, old_val, new_val)
// replace_copy_if(beg, end, dest, preb, new_val)


/*
*（1）replace(beg, end, old_val, new_val)
* 将 [beg, end) 范围内的元素中值为 old_val 的元素替换成值 new_val。
*（2）replace_if(beg, end, preb, new_val)
* 将 [beg, end) 范围内的使得谓词 preb 值非 0 的元素替换成值 new_val。
* （3）replace_copy(beg, end, dest, old_val, new_val)
* 将 [beg, end) 范围内的元素中值为 old_val 的元素拷贝到 dest 并将拷贝过去的值替换成 new_val。
*（4）replace_copy_if(beg, end, dest, preb, new_val)
* 将 [beg, end) 范围内的使得谓词 preb 值非 0 的元素拷贝到 dest 并将拷贝过去的值替换成 new_val。
*/
