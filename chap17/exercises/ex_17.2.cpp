//练习 17.2：定义一个 tuple，保存一个 string、一个 vector<string> 和一个 pair<string, int>。

#include <string>
#include <tuple>
#include <utility>
#include <vector>

using std::pair;
using std::string;
using std::tuple;
using std::vector;

int main() {
    tuple<string, vector<string>, pair<string, int>> something;

    return 0;
}
