//练习 3.2：编写一段程序从标准输入中一次读取一整行，然后修改该成簇使其一次读入一个词。

#include <iostream>
#include <string>

//一次读取一整行
// int main()
// {
//     using std::cin;
//     using std::cout;
//     using std::endl;
//     using std::string;

//     string str;
//     cout << "请输入一句话：" << endl;
//     std::getline(cin, str);
//     cout << "刚才输入的话是：" << endl;
//     cout << str << endl;

//     return 0;
// }

//一次读取一个词
int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::string;

    string str;
    cout << "请输入一句话，词语之间用空格分割：" << endl;
    cin >> str;
    cout << "读取到的第一个词语是：" << endl;
    cout << str << endl;

    return 0;
}