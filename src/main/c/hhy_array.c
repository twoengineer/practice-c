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

int hhy_array_at(hhy_array_t *a, int index) {
    assert(index >= 0);
    assert(index < a->len);
    int *data = a->data;
    return *(data + index);
}

void hhy_array_push(hhy_array_t *a, int item) {
    hhy_array_resize(a);
    int *data = a->data;
    *(data + a->len) = item;
    a->len++;
}

void hhy_array_insert(hhy_array_t *a, size_t index, int item) {
    assert(index <= a->len);
    hhy_array_resize(a);
    int *data = a->data;
    for (size_t i = a->len; i > index; i--) {
        *(data + i) = *(data + i -1);
    }
    *(data + index) = item;
    a->len++;
}

void hhy_array_prepend(hhy_array_t *a, int item) {
    hhy_array_insert(a, 0, item);
}

int hhy_array_pop(hhy_array_t *a) {
    int *data = a->data;
    int popVal = *(data + a->len - 1);
    *(data + a->len - 1) = 0;
    a->len--;
    return popVal;
}

int hhy_array_delete(hhy_array_t *a, size_t index) {
    assert(index < a->len);
    int *data = a->data;
    int deleteVal = *(data + index);
    for (size_t i = index; i < a->len; i++) {
        *(data + i) = *(data + i + 1);
    }
    a->len--;
    return deleteVal;
}

// not very to use
int *hhy_array_remove_1(hhy_array_t *a, int item) {
    int *data = a->data;
    size_t n = 0;
    int *tIndexs = (int *)malloc(sizeof(int) * a->len);
    for (size_t i = 0; i < a->len; i++) {
        if (*(data + i) == item) {
            tIndexs[n] = i;
            n++;
        }
    }

    for (size_t m = 0; m < a->len; m++) {
        if (*(data + m) == item) {
            hhy_array_delete(a, m);
        }
    }


    if (n < a->len) {
        int *indexs = (int *)malloc(sizeof(int) * n);
        for (size_t j = 0; j < n; j++) {
            indexs[j] = tIndexs[j];
        }
        free(tIndexs);
        return indexs;
    } else {
        return tIndexs;
    }
}

hhy_array_t *hhy_array_remove(hhy_array_t *a, int item) {
    hhy_array_t *indexs = hhy_array_create_int(a->len);
    int *data = a->data;
    for (size_t i = 0; i < a->len; i++) {
        if (*(data + i) == item) {
            hhy_array_push(indexs, i);
        }
    }

    for (size_t m = 0; m < a->len; m++) {
        if (*(data + m) == item) {
            hhy_array_delete(a, m);
        }
    }

    return indexs;
}

int hhy_array_find(hhy_array_t *a, int item) {
    int *data = a->data;
    for (size_t i = 0; i < a->len; i++) {
        if (*(data + i) == item) {
            return i;
        }
    }
    return -1;
}

void hhy_array_to_string(hhy_array_t *a) {
    printf("current array info:\n");
    printf("current array length is %zu\n", hhy_array_size(a));
    printf("current array capacity is %zu\n", hhy_array_capacity(a));
    int *data = a->data;
    for (size_t i = 0; i < a->len; i++) {
          printf("current array index %zu value is %d\n", i, *(data + i));
    }
    printf("current array info end!\n");
}
