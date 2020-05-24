//练习 15.36：在构造函数和 repo 中添加打印语句，以检查你对本节第一个练习中（a）、（b）两小题的回答是否正确。

#include "Query.h"

int main() {
    Query q = Query("fiery") & Query("bird") | Query("wind");

    std::cout << q;

    return 0;
}
