//练习 3.45：再一次改写程序，这次使用 auto 关键字。

#include <iostream>

using std::cout;
using std::endl;

int main() {
  int ia[3][4] = {{0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11}};

  // 版本 1
  cout << "版本 1 输出的结果：" << endl;
  for (auto &row : ia) {
    for (auto col : row) cout << col << " ";
    cout << endl;
  }

  //版本 2
  cout << "版本 2 输出的结果：" << endl;
  for (auto r = 0; r != 3; ++r) {
    for (auto c = 0; c != 4; ++c) cout << ia[r][c] << " ";
    cout << endl;
  }

  //版本 3
  cout << "版本 3 输出的结果：" << endl;
  for (auto *row = ia; row != ia + 3; ++row) {
    for (auto *col = *row; col != *row + 4; ++col) cout << *col << " ";
    cout << endl;
  }

  return 0;
}
