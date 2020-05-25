//练习 15.41：重新实现你的类，这次使用指向 Query_base 的内置指针而非 shared_ptr。请注意，
//做出上述改动后，你的类将不能再使用合成的拷贝控制成员。

#include "Query2.h"
#include "TextQuery.h"

int main() {
    std::ifstream ifs("story.data");
    TextQuery text(ifs);

    Query q = Query("fiery") & Query("bird") | Query("wind");
    auto result = q.eval(text);

    print(std::cout, result);

    return 0;
}

//暂时还未解决

//TODO...
