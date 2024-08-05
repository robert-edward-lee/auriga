#ifndef H_COMMON
#define H_COMMON

#include <stdbool.h>
#include <stdio.h>

#define countof(arr) (sizeof(arr) / sizeof(arr[0]))

#define do_test(func, test) \
    if(func(test.str) != test.flag) { \
       printf("wrong: " #func "(\"%s\") != %s\n", test.str, test.flag ? "true" : "false"); \
    }

#define do_tests(func, tests) \
    for(size_t i = 0; i < countof(tests); ++i) { \
        do_test(func, tests[i]); \
    }

typedef struct {
    const char *str;
    bool flag;
} Test;

#endif /* H_COMMON */
