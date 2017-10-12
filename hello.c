/* hello world */
#include <stdio.h>
#include <sys/resource.h>

void* test(void* arg)
{
  printf("%s\n", (char*)arg);
  return (void*)0;
}

int main(int argc, char **argv)
{
  //利用setrlimit函数我们可以将"core file size"设置成一个非0值,这样就可以在崩溃时自动生成core文件了
  struct rlimit res = { .rlim_cur = RLIM_INFINITY, .rlim_max = RLIM_INFINITY };
  setrlimit(RLIMIT_CORE, &res);

  //使用数组
  int i, a[5];
  for(i=0; i<5; i++) {
    a[i] = i;
    printf("%d\n", a[i]);
  }

  printf("%s\n", "Hello, World");
  return 0;
}

/*
operator:
  gcc
    -g                          Generate debug information in default format
    -E                          Preprocess only; do not compile, assemble or link
    -S                          Compile only; do not assemble or link
    -c                          Compile and assemble, but do not link
    -o <file>                   Place output into <file>
    -W                          This switch is deprecated; use -Wextra instead
    -Wextra                     Print extra (possibly unwanted) warnings
    -shared                     Create a shared library
    -fpic                       Generate position-independent code if possible (small mode)
    -fpie                       Generate position-independent code for executables if possible (small mode)

  gcc -g -c hello.c
  gcc -g hello.c -o hello
  gcc -shared -fpic stack.c -o hello.so
*/
