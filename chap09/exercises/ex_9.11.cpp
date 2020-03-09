//练习 9.11：对 6 种创建和初始化 vector 的方法，每一种都给出一个实例。解释每个 vector 包含什么值。

/*
* (1) vector<int> ivec0;                                // ivec0 包含 0 个元素。
* (2) vector<int> ivec1(6);                             // ivec1 包含 6 个 0。
* (3) vector<int> ivec2{1,2,3,4,5,6};                   // ivec2 包含 1，2，3，4，5，6 共 6 个元素
* (4) vector<int> ivec3(ivec2);                         // ivec3 包含与 ivec2 完全一样的元素
* (5) vector<int> ivec4(6, 1);                          // ivec4 包含 6 个 1。
* (6) vector<int> ivec5(ivec3.begin(), ivec3.end());    // ivec5 包含与 ivec3 完全一样的元素。
*/
