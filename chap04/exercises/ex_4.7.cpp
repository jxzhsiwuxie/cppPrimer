//练习 4.7：溢出是何含义？写出三条导致溢出的表达式。
/*
 *当表达式的计算结果超出该类型能表示的范围时就会产生溢出。
 */

#include <iostream>

int main() {
  short si = 32767, si2 = -32768;
  int ii = 100000;

  si += 1;  //-32768
  std::cout << si << std::endl;

  si2 -= 1;  //- 32768
  std::cout << si << std::endl;

  si = ii;  // - 31072
  std::cout << si << std::endl;

  return 0;
}
