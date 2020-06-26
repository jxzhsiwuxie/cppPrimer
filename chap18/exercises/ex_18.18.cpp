//练习 18.18：已知有下面的 swap 的典型定义（参见 13.3 节，第 457 页），当 mem1 是一个 string 时，程序使用 swap 的哪个版本？
//如果 mem1 是 int 呢？说明在这两种情况下名字查找过程。
// void swap(T v1, T v2){
//     using std::swap;
//     swap(v1.mem1, v2.mem1);
//     //交换类型 T 的其它成员
// }

/*
* 如果 mem1 是一个 string，则使用 stirng 头文件中定义的 swap，如果 mem1 是一个 int，则使用标准库的 swap。
*/

