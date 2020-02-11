//编写程序，统计输入中有多少个元音字母。

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
    int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
    char ch;
    cout << "输入一个英文句子：" << endl;

    while (cin >> ch) {
        switch (ch) {
            case 'a':
                ++aCnt;
                break;
            case 'e':
                ++eCnt;
                break;
            case 'i':
                ++iCnt;
                break;
            case 'o':
                ++oCnt;
                break;

            case 'u':
                ++uCnt;
                break;
            default:
                break;
        }
    }

    cout << "句子中共有元音字母 a " << aCnt << " 个， \n"
         << "句子中共有元音字母 e " << eCnt << " 个， \n"
         << "句子中共有元音字母 i " << iCnt << " 个， \n"
         << "句子中共有元音字母 o " << oCnt << " 个， \n"
         << "句子中共有元音字母 u " << uCnt << " 个。 \n"
         << endl;

    return 0;
}
