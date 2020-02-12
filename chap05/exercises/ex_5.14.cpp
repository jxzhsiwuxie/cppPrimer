//练习 5.14：编写一段程序，从标准输入中读取若干 string 对象并查找连续重复出现的单词。所谓连续重复出现的意思是：
//一个单词后面紧跟着这个单词本身。要求记录连续出现的单词的最大次数以及对应的单词。如果这样的单词存在，
//输出连续出现的最大次数；如果不存在，输出一条信息说明任何单词都没有连续出现过。例如，如果输入是
//how now now now brown cow cow
//那么输出应该表明单词 now 连续出现了 3 次。

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
    string finalStr, multStr, tmpStr;
    int finalCnt = 1, cnt = 1;

    cout << "输入一句话，包含多个英文单词：" << endl;

    if (cin >> multStr) {
        while (cin >> tmpStr) {
            if (multStr == tmpStr) {
                ++cnt;
                if (cnt > finalCnt) {
                    finalStr = multStr;
                    finalCnt = cnt;
                }
            } else {
                cnt = 0;
                multStr = tmpStr;
            }
        }
    }

    if (finalCnt == 1)
        cout << "没有重复出现的单词" << endl;
    else
        cout << "连续重复出现的单词是：" << finalStr << "；连续重复出现 " << finalCnt << " 次" << endl;

    return 0;
}
