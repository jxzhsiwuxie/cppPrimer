//练习 12.27：TextQuery 和 QueryResult 类只使用了我们介绍过的语言和标准库特性。不要提前看后续章节的内容，
//只用已经学到的知识对这两个类编写你自己的版本。

#include <fstream>
#include <iostream>
#include <string>

#include "QueryResult.h"
#include "TextQuery.h"

int main() {
    std::ifstream ifs("strblob.txt");
    TextQuery tq(ifs);

    QueryResult qr;
    qr.setText(tq.getText());

    qr.print(std::cout, "and");

    return 0;
}