#include <stdio.h>
#include <sys/resource.h>
#include "hhy_array.h"

int main(int argc, char** argv) {
  //利用setrlimit函数我们可以将"core file size"设置成一个非0值,这样就可以在崩溃时自动生成core文件了
  struct rlimit res = { .rlim_cur = RLIM_INFINITY, .rlim_max = RLIM_INFINITY };
  setrlimit(RLIMIT_CORE, &res);

  hhy_array_t *a = hhy_array_create_int(10);
  printf("array length is %zu\n", hhy_array_size(a));
  printf("array capacity is %zu\n", hhy_array_capacity(a));
  printf("current array is or not empty. 1 is empty, 0 is not. result is: %d\n", hhy_array_is_empty(a));
  return 0;
}