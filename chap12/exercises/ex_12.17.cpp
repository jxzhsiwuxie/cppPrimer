//练习 12.17：下面的 unique_ptr 声明中，哪些是合法的，哪些可能导致后续的程序错误？解释每个错误的问题在哪。
// int ix = 1024, *pi = &ix, *pi2 = new int(2048);
// typedef unique_ptr<int> IntP;
// (a) IntP p0(ix);             (b) IntP p1(pi);
// (c) IntP p2(pi2);            (d) IntP p3(&ix);
// (e) IntP p4(new int(2048));  (f) IntP p5(p2.get());  


/*
* (a) 不合法，参数 ix 是一个整型而不是指针。
* (b) 不合法，pi 指向的内存不是通过 new 分配的。
* (c) 合法，但是混合使用内置指针和 unique_ptr 可能会增加出错的机会。
* (d) 不合法，同 (b)。
* (e) 合法。
* (f) 合法，但是容易造成错误。
*/
