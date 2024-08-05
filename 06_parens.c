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
    { "(}", false },
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
    int rounds = 0, boxes = 0, curlies = 0;

    if(!s) {
        return false;
    }

    while(*s) {
        switch(*s++) {
            case '(':
                ++rounds;
                break;
            case ')':
                --rounds;
                break;
            case '[':
                ++boxes;
                break;
            case ']':
                --boxes;
                break;
            case '{':
                ++curlies;
                break;
            case '}':
                --curlies;
                break;
            default:
                return false;
        }

        if(rounds < 0 || boxes < 0 || curlies < 0) {
            return false;
        }
    }

    return !rounds && !boxes && !curlies;
}

int main(void) {
    do_tests(is_correct_simple, tests_simple);

    do_tests(is_correct, tests);

    return 0;
}
