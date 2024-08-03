#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define countof(arr) (sizeof(arr) / sizeof(arr[0]))

bool is_palindrome(const char *s) {
    const char *begin, *end;

    if(!s) {
        return false;
    }

    begin = s;
    end = s + strlen(s) - 1;

    while(begin <= end) {
        if(*begin++ != *end--) {
            return false;
        }
    }

    return true;
}

struct {
    const char *str;
    bool flag;
} tests[] = {
    { NULL, false },
    { "", true },
    { "abc", false },
    { "aba", true },
    { "abba", true },
    { "abac", false },
};

int main(void) {
    int i;

    for(i = 0; i < countof(tests); ++i) {
        if(is_palindrome(tests[i].str) != tests[i].flag) {
            printf("wrong: is_palindrome(\"%s\") != %s\n", tests[i].str, tests[i].flag ? "true" : "false");
        }
    }

    return 0;
}
