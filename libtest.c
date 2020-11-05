#include "foo.h"

int foo();

__attribute__((constructor(103))) void initfoo() {
  nprint("begin libtest constructor\n");
  nesting++;
  nprint("libtest calling foo_init\n");
  CALL(foo_init());
  nprint("libtest calling foo_init returned\n");
  nprint("libtest calling foo\n");
  CALL(foo());
  nprint("libtest calling foo returned\n");
  nesting--;
  nprint("end libtest constructor\n");
}

int bar() { nprint("libtest bar called\n"); }
