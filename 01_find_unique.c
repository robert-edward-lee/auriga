#include <stdbool.h>
#include <stdio.h>

#define countof(arr) (sizeof(arr) / sizeof(arr[0]))

bool is_unique(const char *s) {
    static bool hist[256] = { false };

    if(!s) {
        return false;
    }

    while(*s) {
        if(hist[*s]) {
            return false;
        }
        hist[*s++] = true;
    }

    return true;
}

struct {
    const char *str;
    bool flag;
} tests[] = {
    { NULL, false },
    { "", true },
    { "abc", true },
    { "aba", false },
};

int main(void) {
    int i;

    for(i = 0; i < countof(tests); ++i) {
        if(is_unique(tests[i].str) != tests[i].flag) {
            printf("wrong: is_unique(\"%s\") != %s\n", tests[i].str, tests[i].flag ? "true" : "false");
        }
    }

    return 0;
}
