#include "Chapter6.h"

int fact(int n) {
    if (n == 0)
        return 1;
    else {
        int ret = 1;
        while (n > 0)
            ret *= n--;
        return ret;
    }
}
