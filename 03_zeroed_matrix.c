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
    size_t i, j;

    if(!mat) {
        return;
    }

    for(j = 0; j < m; ++j) {
        for(i = 0; i < n; ++i) {
            printf("% 3d ", mat[j][i]);
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
    (int[3]){ 0, -5, 2 },
    (int[3]){ 2, 5, 2 },
    (int[3]){ 8, -1, 6 },
};

int *m2[] = {
    (int[3]){ 0, 0, 0 },
    (int[3]){ 0, 5, 2 },
    (int[3]){ 0, -1, 6 },
};

int main(void) {
    mat_print(m1, 3, 3);
    printf("\n");
    mat_print(m2, 3, 3);

    printf("m1 == m1 = %d\n", mat_eq(m1, m1, 3, 3));
    printf("m1 == m2 = %d\n", mat_eq(m1, m2, 3, 3));

    return 0;
}
