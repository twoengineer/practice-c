#ifndef PRACTICE_C_DYNAMIC_ARRAY_H__
#define PRACTICE_C_DYNAMIC_ARRAY_H__

typedef struct {
  void *data;
  size_t len;
  size_t cap;
} hhy_array_t;

hhy_array_t *hhy_array_create_int(size_t size);
size_t hhy_array_size(hhy_array_t *a);
size_t hhy_array_capacity(hhy_array_t *a);
void hhy_array_resize(hhy_array_t *a);
int hhy_array_is_empty(hhy_array_t *a);

#endif