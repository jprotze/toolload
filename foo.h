#include <stdio.h>

extern int nesting;

#define nprint(...)                                                            \
  do {                                                                         \
    if (nesting == 0)                                                          \
      printf(__VA_ARGS__);                                                     \
    if (nesting == 1)                                                          \
      printf("  " __VA_ARGS__);                                                \
    if (nesting == 2)                                                          \
      printf("    " __VA_ARGS__);                                              \
    if (nesting == 3)                                                          \
      printf("      " __VA_ARGS__);                                            \
    if (nesting == 4)                                                          \
      printf("        " __VA_ARGS__);                                          \
    if (nesting >= 5)                                                          \
      printf("          " __VA_ARGS__);                                        \
  } while (0)

#define CALL(f)                                                                \
  nesting++;                                                                   \
  f;                                                                           \
  nesting--

int pfoo();
int foo();

int pfoo_init();
int foo_init();

int pfoo_register();
int foo_register();
