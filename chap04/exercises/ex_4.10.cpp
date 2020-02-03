//练习 4.10：为 while 循环写一个条件，使其从标准输入中读取整数，遇到 42 时停止。

#include <iostream>

int main() {
  int val;
  while (std::cin >> val && val != 42) {
    // TODO
  }

  return 0;
}
