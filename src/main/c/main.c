#include <stdio.h>
#include <sys/resource.h>
#include "hhy_array.h"

void test_hhy_array_t() {
  hhy_array_t *a = hhy_array_create_int(10);
  hhy_array_to_string(a);
  printf("current array is or not empty. 1 is empty, 0 is not. result is: %d\n", hhy_array_is_empty(a));

  hhy_array_push(a, 0);
  hhy_array_push(a, 1);
  hhy_array_push(a, 2);
  hhy_array_push(a, 3);
  hhy_array_push(a, 4);
  hhy_array_insert(a, 2, 22);
  hhy_array_insert(a, 3, 33);
  hhy_array_insert(a, 4, 44);
  hhy_array_prepend(a, 100);
  hhy_array_push(a, 5);
  hhy_array_push(a, 6);
  hhy_array_push(a, 7);
  hhy_array_push(a, 8);
  hhy_array_push(a, 9);
  hhy_array_push(a, 5);
  hhy_array_push(a, 10);
  hhy_array_push(a, 11);
  hhy_array_push(a, 5);
  hhy_array_push(a, 12);
  hhy_array_to_string(a);

  hhy_array_pop(a);
  hhy_array_delete(a, 0);
  hhy_array_delete(a, 1);
  hhy_array_delete(a, 2);
  hhy_array_t *indexs = hhy_array_remove(a, 5);
  hhy_array_to_string(a);
  printf("from array remove item 5, data indexs:\n");
  hhy_array_to_string(indexs);
  printf("from array remove item 5, data indexs end!\n");

  int index5 = hhy_array_find(a, 5);
  int index12 = hhy_array_find(a, 12);
  int index11 = hhy_array_find(a, 11);
  printf("item 5 index is %d\n", index5);
  printf("item 12 index is %d\n", index12);
  printf("item 11 index is %d\n", index11);
}

int main(int argc, char** argv) {
  // 利用setrlimit函数我们可以将"core file size"设置成一个非0值,这样就可以在崩溃时自动生成core文件了
  struct rlimit res = { .rlim_cur = RLIM_INFINITY, .rlim_max = RLIM_INFINITY };
  setrlimit(RLIMIT_CORE, &res);

  // test hhy dynamic array
  test_hhy_array_t();

  return 0;
}