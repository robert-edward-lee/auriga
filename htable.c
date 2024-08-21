#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "htable.h"

#define K 31 /* https://algorithmica.org/ru/hashing */
static size_t hash(const void *data, size_t size, size_t mod) {
    size_t h = 0, m = 1;
    const char *it;

    if(!data || !size || !mod) {
        return 0;
    }

    for(it = data; it < (const char *)data + size; ++it) {
        h = (h + m * (*it - 'a' + 1)) % mod;
        m = (m * K) % mod;
    }

    return h;
}

htable_t *htable_new(size_t size) {
    htable_t *table;

    table = malloc(sizeof(*table));
    if(!table) {
        return NULL;
    }

    table->item = calloc(size, sizeof(*table->item));
    if(!table->item) {
        free(table);
        return NULL;
    }

    table->size = size;
    return table;
}

void htable_del(htable_t *table) {
    size_t i;
    htable_node_t *node;

    if(table) {
        if(table->item) {
            for(i = 0; i < table->size; ++i) {
                for(node = table->item[i]; node; node = node->next) {
                    free(node);
                }
            }
            free(table->item);
        }
        free(table);
    }
}

bool htable_insert(htable_t *table, const htable_data_t *data, size_t size) {
    size_t i;
    htable_node_t *node, *new_node;

    if(!table || !data || !size) {
        return false;
    }


    new_node = malloc(sizeof(*new_node));
    if(!new_node) {
        return false;
    }
    new_node->data = malloc(sizeof(*data) * size);
    if(!new_node->data) {
        free(new_node);
        return false;
    }

    memcpy(new_node->data, data, size);
    new_node->size = size;
    new_node->next = NULL;

    i = hash(data, size, table->size);
    if(!table->item[i]) {
        table->item[i] = new_node;
        return true;
    }

    node = table->item[i];
    if(node) { /* process collision */
        while(node->next) {
            node = node->next;
        }
    }
    node->next = new_node;
    return true;
}

bool htable_has(htable_t *table, const htable_data_t *data, size_t size) {
    htable_node_t *node;

    if(!table || !data || !size) {
        return false;
    }

    for(node = table->item[hash(data, size, table->size)]; node; node = node->next) {
        if((node->size == size) && !memcmp(node->data, data, size)) {
            return true;
        }
    }

    return false;
}

void htable_print(const htable_t *table, void (*pr_fn)(const htable_data_t *, size_t)) {
    size_t i;
    htable_node_t *node;

    if(!table) {
        return;
    }

    for(i = 0; i < table->size; ++i) {
        if(table->item[i]) {
            printf("[%03zu]", i);
            for(node = table->item[i]; node; node = node->next) {
                printf(" - \"");
                pr_fn(node->data, node->size);
                printf("\"");
            }
            printf("\n");
        }
    }
}
