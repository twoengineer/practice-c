#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/resource.h>

typedef struct slice {
  void *data;
  size_t len;
  size_t cap;
} slice;

slice * sliceCreate(void *data, size_t len, size_t cap) {
  // allocate memory from the heap
  slice *s = (struct slice *)malloc(sizeof(struct slice));
  s->data = data;
  s->len = len;
  s->cap = cap;
  return s;
}

void reallocateSlice(slice *s) {
  size_t newCap = 2 * s->cap;
  int *old = s->data;
  int *new = (int *)malloc(newCap * sizeof(int));
  for (size_t i = 0; i < s->len; ++i)
  {
     *(new + i) = *(old + i);
  }
  s->data = new;
  s->cap = newCap;
}

size_t size(slice *s) {
  return s->len;
}

size_t capacity(slice *s) {
  return s->cap;
}

bool is_empty(slice *s) {
  return s->len == 0 ? false : true;
}

int *at(slice *s, int index) {
  assert(index <= s->cap);
  int *sa = s->data;
  return sa + index - 1;
}

void push(slice *s, int item) {
  if (s->len == s->cap) {
    reallocateSlice(s);
  }
  int *d = s->data;
  *(d + s->len) = item;
  s->len++;
}

int main(int argc, char **argv) {
  //利用setrlimit函数我们可以将"core file size"设置成一个非0值,这样就可以在崩溃时自动生成core文件了
  struct rlimit res = { .rlim_cur = RLIM_INFINITY, .rlim_max = RLIM_INFINITY };
  setrlimit(RLIMIT_CORE, &res);

  //使用数组
  int i, a[5];
  for(i=0; i<5; i++) {
    a[i] = i;
    printf("%d\n", a[i]);
  }

  int b[5]={ 1, 2, 3, 4, 5 };
  for(i=0; i<5; i++) {
    b[i] = i;
    printf("%d\n", b[i]);
  }

  slice* s = sliceCreate(&b, 5, 5);
  printf("array length is %zu\n", s->len);
  printf("array caption is %zu\n", s->cap);
  printf("%s\n", "dynamic array content");
  int *sa = s->data;
  for (int i = 0; i < s->len; ++i) {
    printf("%d\n", *(sa + i));
  }
  free(s);

  int b2[10];
  slice* s2 = sliceCreate(&b2, 0, 10);
  printf("%s\n", "empty dynamic array content");
  int *s2a = s2->data;
  for (int i = 0; i < 10; ++i) {
    *(s2a + i) = i;
    s2->len++;
    printf("%d\n", *(s2a + i));
  }
  printf("array length is %zu\n", s2->len);
  printf("array caption is %zu\n", s2->cap);
  printf("array is or not empty %d\n", is_empty(s2));
  int *a8 = at(s2, 8);
  printf("array at 8 value is %d\n", *a8);
  printf("array at 9 value is %d\n", *at(s2, 9));
  push(s2, 10);
  int *s2a1 = s2->data;
  for (int i = 0; i < 11; ++i) {
    printf("%d\n", *(s2a1 + i));
  }
  printf("array at 10 value is %d\n", *at(s2, 10));
  push(s2, 11);
  printf("array at 11 value is %d\n", *at(s2, 11));
  printf("array at 12 value is %d\n", *at(s2, 12));
  free(s2);
  return 0;
}