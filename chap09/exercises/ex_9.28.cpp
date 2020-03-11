//练习 9.28：编写一个函数，接受一个 forward_list 和两个 stirng 共三个参数。函数应该在列表中查找第一个 string，
//并将第二个 string 插入到紧接着第一个 string 之后的位置。若第一个 string 未在链表中，则将第二个 string 插入到链表末尾。

#include <forward_list>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::forward_list;
using std::string;

void insertStr(forward_list<string> &, const string &, const string &);

int main() {
    forward_list<string> strs = {"abc", "def", "ghi", "jkl"};
    string str0 = "abc", str1 = "hahaha", str2 = "mno";

    cout << "初始时 forward_list 包含元素：" << endl;
    for (auto s : strs)
        cout << s << " ";
    cout << endl;

    insertStr(strs, str0, str1);
    cout << "第一次调用函数之后 forward_list 包含元素：" << endl;
    for (auto s : strs)
        cout << s << " ";
    cout << endl;

    insertStr(strs, str2, str2);
    cout << "第二次调用函数之后 forward_list 包含元素：" << endl;
    for (auto s : strs)
        cout << s << " ";
    cout << endl;

    return 0;
}

void insertStr(forward_list<string> &flst, const string &s1, const string &s2) {
    auto curr = flst.begin(), prev = flst.before_begin(), end = flst.end();
    while (curr != end) {
        if (*curr == s1)
            break;
        else {
            ++curr;
            ++prev;
        }
    }

    if (curr != end)
        flst.insert_after(curr, s2);
    else
        flst.insert_after(prev, s2);
}
