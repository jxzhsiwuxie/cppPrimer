//练习 5.10：：我们之前实现的统计元音字母的程序存在一个问题：如果元音字母以大写形式出现，不会被统计在内。
//编写一段程序，统计元音字母的小写形式，也统计大写形式，也就是说，新程序遇到 'a' 和 'A' 都因该递增 aCnt 的值，以此类推。

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
            case 'A':
                ++aCnt;
                break;
            case 'e':
            case 'E':
                ++eCnt;
                break;
            case 'i':
            case 'I':
                ++iCnt;
                break;
            case 'o':
            case 'O':
                ++oCnt;
                break;
            case 'u':
            case 'U':
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
