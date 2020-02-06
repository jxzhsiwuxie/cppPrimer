//练习 4.31：本节程序使用了前置版本的递增运算符和递减运算符，解释为什么要使用前置版本而不使用后置版本。
//要想使用后置版本的递增递减运算符需要做哪些改动？使用后置版本重写本节的程序。

/*
* 本节的程序：
* vector<int>::size_type cnt = ivec.size();
* for(vector<int>::size_type ix = 0; ix != ivec.size(); ++ix, --cnt)
*     ivec[ix]= cnt;
*/

/*
* 就这一段程序而言应该没区别啊（养成习惯？效率高一点？）。
* 可以直接替换成后置递增和递减。
*/

#include <iostream>
#include <vector>

int main() {
    using std::cout;
    using std::endl;
    using std::vector;

    vector<int> ivec(10);
    vector<int>::size_type cnt = ivec.size();

    //前置版本
    for (vector<int>::size_type ix = 0; ix != ivec.size(); ++ix, --cnt)
        ivec[ix] = cnt;
    cout << "使用前置版本后，ivec 的内容：" << endl;
    for (auto n : ivec)
        cout << n << " ";
    cout << endl;

    //恢复默认值
    for (auto &n : ivec)
        n = 0;
    cnt = ivec.size();

    //后置版本
    for (vector<int>::size_type ix = 0; ix != ivec.size(); ix++, cnt--)
        ivec[ix] = cnt;
    cout << "使用后置版本后，ivec 的内容：" << endl;
    for (auto n : ivec)
        cout << n << " ";
    cout << endl;

    return 0;
}
