#include <stdlib.h>

#include "common.h"
#include "stack.h"

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
    { "[[((]]))", false },
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
    Stack stack;

    if(!s) {
        return false;
    }
    printf("\n%s:\n", s);

    stack = Stack_new();

    while(*s) {
        switch(*s) {
            case '(':
            case '[':
            case '{':
                Stack_push(&stack, *s);
                break;
            case ')':
                if(Stack_peek(&stack) != '(') {
                    goto err;
                }
                Stack_pop(&stack);
                break;
            case ']':
                if(Stack_peek(&stack) != '[') {
                    goto err;
                }
                Stack_pop(&stack);
                break;
            case '}':
                if(Stack_peek(&stack) != '{') {
                    goto err;
                }
                Stack_pop(&stack);
                break;
            default:
                return false;
        }
        Stack_print(&stack);
        ++s;
    }

    printf("%s\n", stack.size ? "err" : "---");
    return !stack.size;
err:
    printf("err\n");
    return false;
}

int main(void) {
    do_tests(is_correct_simple, tests_simple);

    do_tests(is_correct, tests);

    return 0;
}
