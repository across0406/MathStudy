#include "../inc/matrixbasictheory.h"

#include <stdio.h>
#include <stdlib.h>

int matrix_definition() {
    // m is row size.
    // n is column size.
    int m = 10;
    int n = 10;

    float* a_dynamic_1d = (float*)malloc(sizeof(float) * m * n);

    float** a_dynamic_2d = (float**)malloc(sizeof(float*) * m);
    for (int i = 0;i < m; i++) {
        a_dynamic_2d[i] = (float*)malloc(sizeof(float) * n);
    }

    int element = 0;
    for (int i = 0; i < m * n; i++) {
        a_dynamic_1d[i] = element++;
    }
    element = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            a_dynamic_2d[i][j] = element++;
        }
    }

    printf("a matrix declared as 1d float array: [\n");

    for (int i = 0; i < m * n; i++) {
        printf("\t%f", a_dynamic_1d[i]);
        
        if ((i + 1) % n == 0) {
            printf("\n");
        }
    }

    printf("\n]\n");

    printf("a matrix declared as 2d float array: [\n");

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("\t%f", a_dynamic_2d[i][j]);

            if (j + 1 == n) {
                printf("\n");
            }
        }
    }

    printf("\n]\n");

    free(a_dynamic_1d);

    for (int i = 0; i < m; i++) {
        free(a_dynamic_2d[i]);
    }

    free(a_dynamic_2d);
}