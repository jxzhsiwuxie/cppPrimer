//练习 5.12：修改统计元音字母的程序，使其能统计含有两个字符的字符序列的数量：ff、fl 和 fi。

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
    int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
    int ffCnt = 0, flCnt = 0, fiCnt = 0;
    char ch, pre = '\0';
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
                if (pre == 'f')
                    ++fiCnt;
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
            case 'f':
                if (pre == 'f')
                    ++ffCnt;
                break;
            case 'l':
                if (pre == 'f')
                    ++flCnt;
                break;
            default:
                break;
        }

        pre = ch;
    }

    cout << "句子中共有元音字母 a " << aCnt << " 个， \n"
         << "句子中共有元音字母 e " << eCnt << " 个， \n"
         << "句子中共有元音字母 i " << iCnt << " 个， \n"
         << "句子中共有元音字母 o " << oCnt << " 个， \n"
         << "句子中共有元音字母 u " << uCnt << " 个， \n"
         << "句子中共有字符序列 ff " << ffCnt << " 个， \n"
         << "句子中共有字符序列 fl " << flCnt << " 个， \n"
         << "句子中共有字符序列 fi " << fiCnt << " 个。 \n"
         << endl;

    return 0;
}
