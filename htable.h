#ifndef H_HTABLE
#define H_HTABLE

#include <stdbool.h>
#include <stddef.h>

#ifndef HTABLE_DATA_TYPE
#define HTABLE_DATA_TYPE char
#endif /* HTABLE_DATA_TYPE */

typedef HTABLE_DATA_TYPE htable_data_t;

typedef struct htable_node_s htable_node_t;
struct htable_node_s {
    htable_data_t *data;
    size_t size;
    htable_node_t *next;
};

typedef struct {
    htable_node_t **item;
    size_t size;
} htable_t;

htable_t *htable_new(size_t size);
void htable_del(htable_t *table);

bool htable_insert(htable_t *table, htable_data_t *data, size_t size);
bool htable_find(htable_t *table, htable_data_t data, size_t size);

#endif /* H_HTABLE */
