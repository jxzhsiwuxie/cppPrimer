//练习 3.44：修改上一个练习中的程序，使用类型别名来代替循环变量的类型。

#include <iostream>

using std::cout;
using std::endl;

int main() {
  int ia[3][4] = {{0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11}};
  using intArray4 = int[4];

  // 版本 1
  cout << "版本 1 输出的结果：" << endl;
  for (intArray4 &row : ia) {
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
  for (intArray4 *row = ia; row != ia + 3; ++row) {
    for (int *col = *row; col != *row + 4; ++col) cout << *col << " ";
    cout << endl;
  }

  return 0;
}
