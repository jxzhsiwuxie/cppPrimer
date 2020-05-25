//练习 15.39：实现 Query 类和 Query_base 类，求图 15.3（第 565 页）中表达式的值并打印相关信息，验证你的程序是否正确。

#include "Query.h"
#include "TextQuery.h"

int main() {
    std::ifstream ifs("story.data");
    TextQuery text(ifs);

    Query q = Query("fiery") & Query("bird") | Query("wind");

    auto result = q.eval(text);

    print(std::cout, result);

    return 0;
}
