//练习 5.22：本节的最后一个例子跳回到 begin，其实使用循环能更好的完成该任务。重写这段程序，注意不再使用 goto 语句。

// begin:
//     int sz = get_size();
//     if(sz < 0) {
//         goto begin;
//     }

// int sz = 0;
// while ((sz = get_size()) < 0) {
//     //...
// }
