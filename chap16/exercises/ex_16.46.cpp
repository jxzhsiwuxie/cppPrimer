//练习 16.46：解释下面的循环，它来自 13.5 节（第 469 页）中的 StrVec::reallocate：
// for(suze_t i = 0; i != size(); ++i)
//     alloc.construct(dest++, std::move(*elem++))

/*
* 在 dest 指针指向的内存中，利用 elem 处的数据构造对象。
* 解引用返回左值。
*/
