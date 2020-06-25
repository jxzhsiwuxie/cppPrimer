//练习 18.3：要想让上面的代码在发生异常时能正常工作，有两种解决方案。请描述这两种方案并实现它们。

/*
*（1）在 exercise 函数内，将可能发生异常的代码放到一个 try 语句块中，并在后面利用 catch 捕捉并处理异常。
*（2）将函数 exercise 的调用放到 try 语句块中，并捕获和处理可能出现的异常
*/

#include <fstream>
#include <stdexcept>
#include <vector>

using std::exception;
using std::ifstream;
using std::vector;

void exercise(int *b, int *e) {
    vector<int> v(b, e);
    int *p = new int[v.size()];
    ifstream in("ints");
    try {
        // 此处发生异常
    } catch (const std::exception &e) {
        // 处理异常情况
    }
}

int main() {
    try {
        int arr[10];
        exercise(arr, arr + 10);
    } catch (const std::exception &e) {
        // 处理异常情况
    }

    return 0;
}
