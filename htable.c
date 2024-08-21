#include <stdlib.h>
#include <string.h>

#include "htable.h"

/* https://algorithmica.org/ru/hashing */
#define K 31
static size_t hash(void *data, size_t size, size_t mod) {
    size_t h = 0, m = 1;
    char *it;

    if(!data || !size || !mod) {
        return 0;
    }

    for(it = data; it < (char *)data + size; ++it) {
        h = (h + m * (*it - 'a' + 1)) % mod;
        m = (m * K) % mod;
    }

    return h;
}

htable_t *htable_new(size_t size) {
    htable_t *table;

    table = malloc(sizeof(*table));
    if(table) {
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
    if(table) {
        if(table->item) {
            free(table->item);
        }
        free(table);
    }
}

bool htable_insert(htable_t *table, htable_data_t *data, size_t size) {
    size_t i;
    htable_node_t *node, *new_node;
    htable_data_t *cont;

    if(!table || !data || !size) {
        return false;
    }

    cont = malloc(size * sizeof(htable_data_t));
    if(!cont) {
        return false;
    }

    i = hash(data, size, table->size);
    node = table->item[i];

    if(node) { /* process collision */
        while(node->next) {
            node = node->next;
        }
    }

    new_node = malloc(sizeof(*new_node));


    memcpy(cont, data, size);
    table->item[i]->data = cont;
    table->item[i]->size = size;
}

bool htable_find(htable_t *table, htable_data_t data, size_t size) {

}
