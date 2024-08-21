#include <stdlib.h>

#include "common.h"

void mat_print(int **mat, size_t n, size_t m) {
    size_t i, j;

    if(!mat) {
        printf("||\n");
        return;
    }

    for(j = 0; j < m; ++j) {
        printf("|");
        for(i = 0; i < n; ++i) {
            printf("% 3d ", mat[j][i]);
        }
        printf("|\n");
    }
}

void mat_zeroed(int **mat, size_t n, size_t m) {
    int *cols, *rows;
    size_t i, j;

    if(!mat || !n || !m) {
        return;
    }

    cols = calloc(n, sizeof(*cols));
    if(!cols) {
        return;
    }
    rows = calloc(m, sizeof(*rows));
    if(!rows) {
        free(cols);
        return;
    }

    for(j = 0; j < m; ++j) {
        for(i = 0; i < n; ++i) {
            if(!mat[j][i]) {
                cols[i] = true;
                rows[j] = true;
            }
        }
    }

    for(i = 0; i < n; ++i) { /* cols */
        if(cols[i]) {
            for(j = 0; j < m; ++j) {
                mat[j][i] = 0;
            }
        }
    }

    for(j = 0; j < m; ++j) { /* rows */
        if(rows[j]) {
            for(i = 0; i < n; ++i) {
                mat[j][i] = 0;
            }
        }
    }
}

bool mat_eq(int **lhs, int **rhs, size_t n, size_t m) {
    size_t i, j;

    if(!lhs || !rhs) {
        return false;
    }

    for(j = 0; j < m; ++j) {
        for(i = 0; i < n; ++i) {
            if(lhs[j][i] != rhs[j][i]) {
                return false;
            }
        }
    }

    return true;
}

int *m1[] = {
    (int[3]){0, -5, 2},
    (int[3]){2,  5, 2},
    (int[3]){8, -1, 6},
};

int *m2[] = {
    (int[3]){0,  0, 0},
    (int[3]){0,  5, 2},
    (int[3]){0, -1, 6},
};

int *m3[] = {
    (int[3]){0, -5, 2},
    (int[3]){2,  5, 2},
    (int[3]){8, -1, 6},
    (int[3]){5,  2, 3},
};

int *m4[] = {
    (int[3]){0,  0, 0},
    (int[3]){0,  5, 2},
    (int[3]){0, -1, 6},
    (int[3]){0,  2, 3},
};

int main(void) {
    printf("m1 = \n");
    mat_print(m1, 3, 3);
    printf("m2 = \n");
    mat_print(m2, 3, 3);

    printf("mat_eq(m1, m1) = %d\n", mat_eq(m1, m1, 3, 3));
    printf("mat_eq(m1, m2) = %d\n", mat_eq(m1, m2, 3, 3));

    mat_zeroed(m1, 3, 3);
    printf("zeroed(m1) = \n");
    mat_print(m1, 3, 3);
    printf("mat_eq(zeroed(m1), m2) = %d\n", mat_eq(m1, m2, 3, 3));
    printf("\n\n");

    printf("m3 = \n");
    mat_print(m3, 3, 4);
    printf("m4 = \n");
    mat_print(m4, 3, 4);

    printf("mat_eq(m3, m3) = %d\n", mat_eq(m3, m3, 3, 4));
    printf("mat_eq(m3, m4) = %d\n", mat_eq(m3, m4, 3, 4));

    mat_zeroed(m3, 3, 4);
    printf("zeroed(m3) = \n");
    mat_print(m3, 3, 4);
    printf("mat_eq(zeroed(m3), m4) = %d\n", mat_eq(m3, m4, 3, 4));
    printf("\n");

    return 0;
}
