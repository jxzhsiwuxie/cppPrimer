//练习 5.11：修改统计元音字母的程序，使其也能统计空格、制表符和换行的数量。

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
    int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
    int spaceCnt = 0, tableCnt = 0, lineCnt = 0;
    string line;
    cout << "输入一段英文句子：" << endl;

    while (std::getline(cin, line)) {
        ++lineCnt;
        for (char ch : line) {
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
                case ' ':
                    ++spaceCnt;
                    break;
                case '\t':
                    ++tableCnt;
                    break;
                default:
                    break;
            }
        }
    }

    cout << "句子中共有元音字母 a " << aCnt << " 个， \n"
         << "句子中共有元音字母 e " << eCnt << " 个， \n"
         << "句子中共有元音字母 i " << iCnt << " 个， \n"
         << "句子中共有元音字母 o " << oCnt << " 个， \n"
         << "句子中共有元音字母 u " << uCnt << " 个， \n"
         << "句子中共有空格 " << spaceCnt << " 个， \n"
         << "句子中共有制表符 " << tableCnt << " 个， \n"
         << "句子中共有换行 " << lineCnt << " 个。 \n"
         << endl;

    return 0;
}
