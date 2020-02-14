//练习 6.2：请指出下列函数哪个有错误，为什么？应该如何修改这些错误呢？
// (a) int f() {
//         string s;
//         //...
//         return s;
//     }
// (b) f2(int i) {/*...*/}
// (c) int calc(int v1, int v1) {/*...*/}
// (d) double square(double x) return x * x;

/*
* (a) 有错误，函数体内返回值类型与函数定义的返回值类型不匹配，可改为：
*/
// string f() {
//      string s;
//      //...
//      return s;
//  }

/*
* (b) 有错误，函数定义没有定义返回值，可改为：
*/
// void f2(int i) {/*...*/}

/*
* (c) 有错误，函数定义中两个形参名称相同，可改为：
*/
// int calc(int v1, int v2) {/*...*/}

/*
* (d) 有错误，函数体应该用大括号包围住，可改为：
*/
// double square(double x) {return x * x;}
