//练习 5.9：编写一段程序，使用一系列 if 语句统计从 cin 读取的文本中有多少个元音字母。

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
    int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0, otherCnt = 0;
    char ch;
    cout << "输入一个英文句子：" << endl;

    while (cin >> ch) {
        if (ch == 'a')
            ++aCnt;
        else if (ch == 'e')
            ++eCnt;
        else if (ch == 'e')
            ++eCnt;
        else if (ch == 'e')
            ++eCnt;
        else if (ch == 'e')
            ++eCnt;
        else
            ++otherCnt;
    }

    cout << "句子中共有元音字母 a " << aCnt << " 个， \n"
         << "句子中共有元音字母 e " << eCnt << " 个， \n"
         << "句子中共有元音字母 i " << iCnt << " 个， \n"
         << "句子中共有元音字母 o " << oCnt << " 个， \n"
         << "句子中共有元音字母 u " << uCnt << " 个。 \n"
         << endl;

    return 0;
}
