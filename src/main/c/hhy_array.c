/*
* use int type to impl hhy dynamic array
*/
#include <assert.h>
#include <stdlib.h>
#include "hhy_array.h"

hhy_array_t *hhy_array_create_int(size_t size) {
    hhy_array_t *a = (hhy_array_t *)malloc(sizeof(hhy_array_t));
    int *data = (int *)malloc(sizeof(int) * size);
    a->data = data;
    a->len = 0;
    a->cap = size;
    return a;
}

size_t hhy_array_size(hhy_array_t *a) {
    return a->len;
}

size_t hhy_array_capacity(hhy_array_t *a) {
    return a->cap;
}

void hhy_array_resize(hhy_array_t *a) {
    size_t nCap = 0;
    if (a->len == a->cap) {
        nCap = 2 * a->cap;
    } else if (a->len < a->cap / 4) {
        nCap = a->cap / 2;
    } else {
        return;
    }

    int *oData = a->data;
    int *nData = (int *)malloc(sizeof(int) * nCap);
    for (size_t i = 0; i< a->len; i++) {
        *(nData + i) = *(oData + i);
    }
    a->data = nData;
    a->cap = nCap;
    free(oData);
}

int hhy_array_is_empty(hhy_array_t *a) {
    return a->len == 0 ? 1 : 0;
}

