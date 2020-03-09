//练习 9.16：重写上一题的程序，比较一个list<int> 中的元素和一个 vector<int> 中的元素。

#include <list>
#include <vector>

using std::list;
using std::vector;

int compare(const list<int> &iList, const vector<int> &iVector) {
    vector<int> tmp(iList.begin(), iList.end());

    if (tmp == iVector)
        return 0;
    else if (tmp < iVector)
        return -1;
    else
        return 1;
}
