//练习 18.4：查看图 18.1（第 693 页）所示的继承体系，说明下面的 try 块有何错误并修改它。
// try {
//      //使用 C++ 标准库
// } catch(exception) {
//      // ...
// } catch(const runtime_error &re) {
//      //...
// } catch(overflow_error eobj) { /* ... */ }

/*
* catch 中出现的异常的类型应该是从上到下越来越基础。
*/

// try {
//      //使用 C++ 标准库
// } catch(overflow_error eobj) {
//      // ...
// } catch(const runtime_error &re) {
//      //...
// } catch(exception) { /* ... */ }
