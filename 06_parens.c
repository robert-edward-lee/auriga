#include "common.h"

Test tests_simple[] = {
    { NULL, false },
    { "", true },
    { "(", false },
    { ")", false },
    { "()", true },
    { ")(", false },
    { ")()", false },
    { "(()()((()))())", true },
    { "(()()((())())", false },
};

Test tests[] = {
    { NULL, false },
    { "", true },
    { "(", false },
    { ")", false },
    { "()", true },
    { ")(", false },
    { ")()", false },
    { "(()()((()))())", true },
    { "{()[]((()))}{}", true },
    { "{()[]((())}{}", false },
};


bool is_correct_simple(const char *s) {
    int cnt = 0;

    if(!s) {
        return false;
    }

    while(*s) {
        switch(*s++) {
            case '(':
                ++cnt;
                break;
            case ')':
                --cnt;
                break;
            default:
                return false;
        }

        if(cnt < 0) {
            return false;
        }
    }

    return !cnt;
}

bool is_correct(const char *s) {
    return true;
}

int main(void) {
    do_tests(is_correct_simple, tests_simple);

    return 0;
}
