#include "foo.h"
#include <dlfcn.h>
#include <stdlib.h>

int pfoo() { nprint("libfoo pfoo()\n"); }

int __attribute__((weak)) __attribute__((noinline)) foo() {
  nprint("libfoo foo()\n");
  CALL(pfoo());
}

int pfoo_register() { nprint("libfoo pfoo_register()\n"); }

int __attribute__((weak)) __attribute__((noinline)) foo_register() {
  nprint("libfoo foo_register()\n");
  CALL(pfoo_register());
}

int pfoo_init() {
  nprint("libfoo pfoo_init()\n");
  const char *fooenv = getenv("FOO_LOAD_LIBRARIES");
  if (fooenv) {
    void *lh = dlopen(fooenv, RTLD_LAZY);
  }
}

int __attribute__((weak)) __attribute__((noinline)) foo_init() {
  nprint("libfoo foo_init()\n");
  CALL(pfoo_init());
}
