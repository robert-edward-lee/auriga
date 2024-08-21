#include "common.h"

Test tests[] = {
    { NULL, false},
    {   "",  true},
    {"abc",  true},
    {"aba", false},
};

bool is_unique(const char *s) {
    bool hist[256] = {false};

    if(!s) {
        return false;
    }

    while(*s) {
        if(hist[(unsigned)*s]) {
            return false;
        }
        hist[(unsigned)*s++] = true;
    }

    return true;
}

int main(void) {
    do_tests(is_unique, tests);

    return 0;
}
