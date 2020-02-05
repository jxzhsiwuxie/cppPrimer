//练习 4.21：编写一段程序，使用条件运算符从 vector<int>
//中找出哪些元素是奇数，然后将这些奇数值翻倍。

#include <iostream>
#include <vector>

int main() {
  using std::cout;
  using std::endl;
  using std::vector;

  vector<int> ivec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

  cout << "修改前 ivec 中的元素：" << endl;
  for (auto n : ivec) cout << n << " ";
  cout << endl;

  for (auto &n : ivec) n = n % 2 == 0 ? n : 2 * n;

  cout << "修改后 ivec 中的元素：" << endl;
  for (auto n : ivec) cout << n << " ";
  cout << endl;

  return 0;
}
