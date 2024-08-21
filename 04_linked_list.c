#include <stdio.h>
#include <string.h>

#include "common.h"
#include "htable.h"

char *strings[] = {
    "",
    "123",
    "132",
    "213",
    "231",
    "312",
    "321",
    "lol",
    "kek",
    "cheburek",
};

void pr_s(const char *str, size_t size) {
    (void)size;
    printf(str);
}

int main(void) {
    htable_t *ht;
    size_t i;


    ht = htable_new(32);
    if(!ht) {
        printf("!ht\n");
        return -1;
    }

    for(i = 0; i < countof(strings); ++i) {
        printf("strings[%zu] = \"%s\"\n", i, strings[i]);

        if(!htable_insert(ht, strings[i], strlen(strings[i]) + 1)) {
            printf("!htable_insert\n");
        }
    }

    htable_print(ht, pr_s);
    htable_del(ht);

    return 0;
}
