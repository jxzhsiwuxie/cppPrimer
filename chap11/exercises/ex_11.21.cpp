//练习 11.21：假定 word_count 是一个 string 到 size_t 的 map，word 是一个 string，解释下面循环的作用：
//  while(cin >> word)
//      ++word_count.insert({word, 0}).first->second;

/*
* 循环向 word_count 中插入 string 并递增插入的关键字对应的 size_t 的值。
*/
