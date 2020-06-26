//练习 18.14：假设下面的 operator* 声明的是嵌套的命名空间 mathLib::MatrixLib 的一个成员：
// namespace mathLib {
//     namespace MatrixLib {
//         class matrix { /* ... */ }
//         matrix operator*(const matrix &, const matrix &);
//         // ...
//     }
// }
//请问该如何在全局作用域中声明该运算符？


/*
* mathLib::MatrixLib::matrix operator*(const mathLib::MatrixLib::matrix &, const mathLib::MatrixLib::matrix &);
*/
