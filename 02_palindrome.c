#include <string.h>

#include "common.h"

Test tests[] = {
    { NULL, false },
    { "", true },
    { "abc", false },
    { "aba", true },
    { "abba", true },
    { "abac", false },
};

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

int main(void) {
    do_tests(is_palindrome, tests);

    return 0;
}
