//练习 18.2：当在指定的位置发生了异常时将出现什么情况？
// void exercise(int *b, int *e){
//      vector<int> v(b, e);
//      int *p = new int[v.size()];
//      ifstream in("ints");
//      // 此处发生异常
// }

/*
* 发生异常后，函数 exercise 停止执行，发生异常位置之后的代码不被执行，in 的析构函数被调用接着变量 in 被消除；指针 p 被消除但是 p 指向的内存没有被释放；
* v 的析构函数被调用，接着变量 v 被消除。最终程序被终止。
*/
