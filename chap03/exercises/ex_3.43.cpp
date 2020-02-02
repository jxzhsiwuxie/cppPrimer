//练习 3.43：编写 3 个不同版本的程序，令其均能输出 ia 的元素。版本 1 使用范围
// for 语句管理迭代过程； 版本 2 和版本 3 都使用普通的 for 语句，其中版本 2
//要求使用下标运算符，版本 3 要求用指针。此外，在 所有 3
//个版本的程序中都要直接写出数据类型，而不能使用类型别名、auto 关键字和 decltype
//关键字。

#include <iostream>

using std::cout;
using std::endl;

int main() {
  int ia[3][4] = {{0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11}};

  // 版本 1
  cout << "版本 1 输出的结果：" << endl;
  for (int(&row)[4] : ia) {
    for (int col : row) cout << col << " ";
    cout << endl;
  }

  //版本 2
  cout << "版本 2 输出的结果：" << endl;
  for (std::size_t r = 0; r != 3; ++r) {
    for (std::size_t c = 0; c != 4; ++c) cout << ia[r][c] << " ";
    cout << endl;
  }

  //版本 3
  cout << "版本 3 输出的结果：" << endl;
  for (int(*row)[4] = ia; row != ia + 3; ++row) {
    for (int *col = *row; col != *row + 4; ++col) cout << *col << " ";
    cout << endl;
  }

  return 0;
}
