#include<stdio.h>
#include<stdlib.h>
#include "countingsort.h"

int countingsort(int n, int *v) {
    int k = n;
    int *v_aux = malloc(k*sizeof(int));

    for (int i = 0; i < k; i++)
        v_aux[i] = 0;

    for (int i = 0; i < k; i++)
        v_aux[v[i]]++;

    int j = 0;
    for (int i = 0; i < k; i++) {
        while (v_aux[i] > 0) {
            v[j] = i;
            v_aux[i]--;
            j++;
        }
    }
    free(v_aux);
}
