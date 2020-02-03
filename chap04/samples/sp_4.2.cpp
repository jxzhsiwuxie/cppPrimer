//算数运算溢出

//当前机器的 short 类型占 16 位，则最大的 short 数值是 32767。
//在这样情况下，下面的计算将会发生溢出。
//当前电脑上打印的 shortValue 值是 -32768。
//0000 0000 0000 0000
//0111 1111 1111 1111 => 32767
//加 1 之后
//1000 0000 0000 0000 => -32768


#include <iostream>

int main() {
  short shortValue = 32767;
  shortValue += 1;

  std::cout << shortValue << std::endl;

  return 0;
}
