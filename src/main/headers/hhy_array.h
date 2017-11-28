#ifndef PRACTICE_C_HHY_ARRAY_H__
#define PRACTICE_C_HHY_ARRAY_H__

typedef struct hhy_array_t {
  void *data;
  size_t len;
  size_t cap;
} hhy_array_t;

hhy_array_t *hhy_array_create_int(size_t size);
size_t hhy_array_size(hhy_array_t *a);
size_t hhy_array_capacity(hhy_array_t *a);
void hhy_array_resize(hhy_array_t *a);
int hhy_array_is_empty(hhy_array_t *a);
int hhy_array_at(hhy_array_t *a, int index);
void hhy_array_push(hhy_array_t *a, int item);
void hhy_array_insert(hhy_array_t *a, size_t index, int item);
void hhy_array_prepend(hhy_array_t *a, int item);
int hhy_array_pop(hhy_array_t *a);
int hhy_array_delete(hhy_array_t *a, size_t index);
int *hhy_array_remove_1(hhy_array_t *a, int item);
hhy_array_t *hhy_array_remove(hhy_array_t *a, int item);
int hhy_array_find(hhy_array_t *a, int item);
void hhy_array_to_string(hhy_array_t *a);

#endif